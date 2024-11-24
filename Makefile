TARGET_EXEC := $(notdir $(shell pwd))

BUILD_DIR := ./build
SRC_DIRS := ./src

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))
CPPFLAGS := $(INC_FLAGS) -MMD -MP


.PHONY: main
# To test a specific problem: 
#	make test={PROBLEM NAMES}
pattern := $(strip $(test))

src_pattern = $(patsubst %, "*%*.c", $(pattern))
topic_pattern = $(patsubst %, "*%*", $(pattern))
find_c_srcs = $(shell find $(1) -name '*.c')
ifeq (${pattern},)
find_topics = $(shell find $(1) -mindepth 1 -maxdepth 1 -type d)
else
find_topics = $(shell find $(1) -mindepth 1 -maxdepth 1 -type d -iname $(call topic_pattern))
find_srcs = $(shell find $(1) -mindepth 2 -maxdepth 2 -iname $(call src_pattern))
endif

day_num := $(words $(shell find ./ -mindepth 1 -maxdepth 1 -type d -name 'day*'))
ifneq ($(day_num),0)
DAY_DIR := ./$(addprefix day, $(shell expr $(day_num)))
topic_dirs := $(call find_topics, $(DAY_DIR))
endif

main_file := $(SRC_DIRS)/main.c 

ifeq ($(topic_dirs),)
prob_srcs := $(call find_srcs, $(DAY_DIR))
prj_srcs := $(call find_srcs, $(SRC_DIRS))
else
prob_srcs := $(call find_c_srcs, $(topic_dirs))
prj_srcs := $(call find_c_srcs, $(addprefix $(SRC_DIRS)/, $(notdir $(topic_dirs))))
endif

PCH:= $(SRC_DIRS)/pch.h
GCH := $(patsubst %, $(BUILD_DIR)/%.gch, $(PCH))
SRCS := $(prob_srcs) $(prj_srcs) $(main_file)
OBJS := $(patsubst %, $(BUILD_DIR)/%.o, $(SRCS))

ifneq ($(prob_srcs),)
main: setup $(BUILD_DIR)/$(TARGET_EXEC)
	@$(BUILD_DIR)/$(TARGET_EXEC)
else
main:
	@echo You need to run 'make generate' first
endif


.PHONY: setup
prob_names := $(foreach problem, $(prob_srcs), $(notdir $(basename $(problem))))
test_funcs := $(foreach prob_name, $(prob_names), $(addsuffix \(\)\;\n, $(addprefix test_, $(prob_name))))
setup:
	@echo 'int main() {' > $(main_file)
	@sed -i '/main/a }' $(main_file)
	@sed -i '/}/i $(test_funcs)' $(main_file)

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	@$(CXX) $(OBJS) -o $@ $(LDFLAGS)

$(GCH): $(PCH)
	@mkdir -p $(dir $@)
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.c.o: %.c $(GCH) 
	# $@
	@mkdir -p $(dir $@)
	@$(CC) $(CPPFLAGS) $(CFLAGS) -include $(PCH)  -c $< -o $@


.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
	rm -rf ./day*
	> $(main_file)

# Including .d makefiles generated from compiler
DEPS := $(OBJS:.o=.d)
-include $(DEPS)


.PHONY: generate
include data.mk
get_srcs = $(patsubst %, $(1)/%.c, $(value $(notdir $(1))))
NEW_DAY := ./$(addprefix day, $(shell expr $(day_num) + 1))
NEW_SRCS := $(foreach topic, $(DSA_TOPICS), $(call get_srcs, $(NEW_DAY)/$(topic)))

$(NEW_SRCS): def_func = $(notdir $(basename $@))
$(NEW_SRCS):
	# Generating $@
	@mkdir -p $(dir $@)
	@touch $@
	@echo '' >> $@
	@echo '$(value $(def_func))' >> $@
	@echo '}' >> $@

generate: $(NEW_SRCS)
