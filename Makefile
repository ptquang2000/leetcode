TARGET_EXEC := $(notdir $(shell pwd))

BUILD_DIR := ./build
SRC_DIRS := ./src
BASED_SRCS := $(shell find $(SRC_DIRS) -maxdepth 1 -name '*.c')
MAIN_FILE := $(filter %main.c, $(BASED_SRCS))

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))
CPPFLAGS := $(INC_FLAGS) -MMD -MP

day_num := $(words $(shell find ./ -maxdepth 1 -type d -name 'day*'))
ifneq ($(day_num),0)
DAY_DIR := ./$(addprefix day, $(shell expr $(day_num)))
endif

.PHONY: main
pattern := $(strip $(test))
ifeq (${pattern},)
find_srcs = $(shell find $(1) -name '*.c')
prob_srcs := $(call find_srcs, $(DAY_DIR))
prj_srcs := $(call find_srcs, $(SRC_DIRS))
else
find_topics = $(shell find $(1) -maxdepth 1 -type d -iname '*$(pattern)*')
topic_dirs := $(call find_topics, $(SRC_DIRS))

ifneq ($(topic_dirs),)
find_srcs = $(shell find $(addprefix $(1)/, $(notdir $(topic_dirs))) -name '*.c')
prob_srcs := $(call find_srcs, $(DAY_DIR))
prj_srcs := $(call find_srcs, $(SRC_DIRS))
else
find_srcs = $(shell find $(1) -mindepth 2 -iname '*$(pattern)*.c')
prob_srcs := $(call find_srcs, $(DAY_DIR))
prj_srcs := $(call find_srcs, $(SRC_DIRS))
endif

prj_srcs += $(BASED_SRCS)
endif

PCH:= $(SRC_DIRS)/pch.h
GCH := $(patsubst %, $(BUILD_DIR)/%.gch, $(PCH))
SRCS := $(prob_srcs) $(prj_srcs)
OBJS := $(patsubst %, $(BUILD_DIR)/%.o, $(SRCS))

ifneq ($(DAY_DIR),)
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
	@echo 'int main() {' > $(MAIN_FILE)
	@sed -i '/main/a }' $(MAIN_FILE)
ifneq ($(test_funcs),)
	@sed -i '/}/i $(test_funcs)' $(MAIN_FILE)
endif

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	@$(CXX) $(OBJS) -o $@ $(LDFLAGS)

$(GCH): $(PCH)
	@mkdir -p $(dir $@)
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.c.o: %.c $(GCH) 
	@mkdir -p $(dir $@)
	@$(CC) $(CPPFLAGS) $(CFLAGS) -include $(PCH)  -c $< -o $@


.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
	rm -rf ./day*
	> $(MAIN_FILE)

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
