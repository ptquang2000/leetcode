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

ifeq ($(topic_dirs),)
prob_srcs := $(call find_srcs, $(DAY_DIR))
prj_srcs := $(call find_srcs, $(SRC_DIRS))
else
prob_srcs := $(call find_c_srcs, $(topic_dirs))
prj_srcs := $(call find_c_srcs, $(addprefix $(SRC_DIRS)/, $(notdir $(topic_dirs))))
endif

SRCS := $(prob_srcs) $(prj_srcs)
OBJS := $(patsubst %, $(BUILD_DIR)/%.o, $(SRCS))

ifneq ($(prob_srcs),)
main: setup $(BUILD_DIR)/$(TARGET_EXEC)
	@$(BUILD_DIR)/$(TARGET_EXEC)
else
main:
	@echo You need to run 'make generate' first
endif


.PHONY: setup
main_file := $(SRC_DIRS)/main.c 
prob_names := $(foreach problem, $(prob_srcs), $(notdir $(basename $(problem))))
test_funcs := $(foreach prob_name, $(prob_names), $(addsuffix \(\)\;, $(addprefix test_, $(prob_name))))
deleted_line := $(shell grep -m 1 -n 'int main()' $(main_file) | awk -F: '{print $$1}')
last_line := $(shell wc -l $(main_file) | awk -F' ' '{print $$1}')
setup:
ifeq ($(deleted_line),)
	@sed -i '1a int main() { $(test_funcs) }' $(main_file)
else
	@sed -i '$(last_line)a int main() { $(test_funcs) }' $(main_file)
	@sed -i '$(deleted_line),$(deleted_line)d' $(main_file)
endif	

# The final build step.
$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	@$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# Build step for C source
$(BUILD_DIR)/%.c.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@


.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
	rm -rf ./day*
ifneq ($(deleted_line),)
	@sed -i '$(deleted_line),$(deleted_line)d' $(main_file)
endif

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
	@echo '#include "defs.h"' >> $@
	@echo '' >> $@
	@echo '$(value $(def_func))' >> $@
	@echo '}' >> $@

generate: $(NEW_SRCS)
