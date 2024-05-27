TARGET_EXEC := $(notdir $(shell pwd))

BUILD_DIR := ./build
SRC_DIRS := ./src
UNITY_DIRS := ./Unity/src
TEST_DIRS := ./test
SCRIPT_DIRS := ./scripts/

# Every folder in ./src will need to be passed to GCC so that it can find header files
INC_DIRS := $(shell find $(SRC_DIRS) $(TEST_DIRS) -type d)
# Add a prefix to INC_DIRS. So moduleA would become -ImoduleA. GCC understands this -I flag
INC_FLAGS := $(addprefix -I,$(INC_DIRS))
# The -MMD and -MP flags together generate Makefiles for us!
# These files will have .d instead of .o as the output.
CPPFLAGS := $(INC_FLAGS) -MMD -MP

src_pattern = $(patsubst %, "*%*.c", $(1))
topic_pattern = $(patsubst %, "*%*", $(1))
find_c_srcs = $(shell find $(1) -name '*.c')
find_topics = $(shell find $(1) -mindepth 2 -maxdepth 2 -type d -iname $(call topic_pattern, $(2)))
find_srcs = $(shell find $(1) -mindepth $(2) -maxdepth $(2) -iname $(call src_pattern, $(3)))

ifeq (${test},)
test := *
endif

pattern := $(strip $(test))

main_srcs := $(TEST_DIRS)/main.c 
unity_srcs := $(call find_c_srcs, $(UNITY_DIRS))

topic_dirs := $(call find_topics, $(SRC_DIRS), $(pattern))
ifeq ($(topic_dirs),)
prob_srcs := $(call find_srcs, $(SRC_DIRS), 3, $(pattern))
test_srcs := $(call find_srcs, $(TEST_DIRS), 2, $(pattern))
else
prob_srcs := $(call find_c_srcs, $(topic_dirs))
test_srcs := $(call find_c_srcs, $(addprefix $(TEST_DIRS)/, $(notdir $(topic_dirs))))
endif

SRCS := $(main_srcs) $(unity_srcs) $(prob_srcs) $(test_srcs)
OBJS := $(patsubst %, $(BUILD_DIR)/%.o, $(SRCS))

.PHONY: main
ifneq ($(prob_srcs),)
main: setup $(BUILD_DIR)/$(TARGET_EXEC)
	@$(BUILD_DIR)/$(TARGET_EXEC)
else
main:
	@echo You need to run 'make generate' first
endif

prob_names := $(foreach problem, $(prob_srcs), $(notdir $(basename $(problem))))
test_funcs := $(foreach prob_name, $(prob_names), $(addsuffix \(\)\;, $(addprefix test_, $(prob_name))))
deleted_line := $(shell grep -m 1 -n 'int main()' $(main_srcs) | cut -d : -f 1)
last_line := $(shell wc -l $(main_srcs) | cut -d ' ' -f 1)
.PHONY: setup
setup:
ifeq ($(deleted_line),)
	@sed -i '$(last_line)a int main() { $(test_funcs) }' $(main_srcs)
else
	@sed -i '$(last_line)a int main() { $(test_funcs) }' $(main_srcs)
	@sed -i '$(deleted_line),$(deleted_line)d' $(main_srcs)
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
	rm -rf $(SRC_DIRS)/*
ifneq ($(deleted_line),)
	@sed -i '$(deleted_line),$(deleted_line)d' $(main_srcs)
endif

# Including .d makefiles generated from compiler
DEPS := $(OBJS:.o=.d)
-include $(DEPS)

include $(SCRIPT_DIRS)/gen_src.mk
