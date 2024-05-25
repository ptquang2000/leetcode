TARGET_EXEC := $(notdir $(shell pwd))

BUILD_DIR := ./build
SRC_DIRS := ./src
UNITY_DIRS := ./Unity/src
TEST_DIRS := ./test

# Find all the C and C++ files we want to compile
# Note the single quotes around the * expressions. The shell will incorrectly expand these otherwise, but we want to send the * directly to the find command.
SUBDIRS := $(shell find $(SRC_DIRS) -mindepth 1 -maxdepth 1 -type d)

# Every folder in ./src will need to be passed to GCC so that it can find header files
INC_DIRS := $(shell find $(SRC_DIRS) $(TEST_DIRS) -type d)
# Add a prefix to INC_DIRS. So moduleA would become -ImoduleA. GCC understands this -I flag
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

# Avoiding make to restart
.PHONY: Makefile

.PHONY: clean
clean:
	# Clearing
	@rm -rf $(BUILD_DIR) $(SRC_DIRS)/defs.c
	@echo Clearing all problems

.PHONY: gen_all
gen_all:
	@echo Generating all problems


# Including .d makefiles generated from compiler
DEPS := $(OBJS:.o=.d)
-include $(DEPS)

test_prob = $(patsubst %, test_%, $(basename $(notdir $(1))))
test_topic = $(notdir $(realpath $(dir $(1))))
format_func = $(patsubst %, %();, $(subst edit_defs_, , $(1)))

edit_defs_%: func = $(call format_func, $@)
edit_defs_%:
	@sed -i '6i $(func)' $(SRC_DIRS)/defs.h

.PHONY: setup
setup:
	@rm -rf $(BUILD_DIR) $(SRC_DIRS)/defs.c
	@cp $(SRC_DIRS)/defs.h.template $(SRC_DIRS)/defs.h
	
# Building C source
$(BUILD_DIR)/%.c.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

.SECONDEXPANSION:

# Linking objects
final := $(BUILD_DIR)/$(TARGET_EXEC)
$(final): objs = $(shell find $(BUILD_DIR) -name '*.o')
$(final): $$(objs)
	@$(CXX) $^ -o $@ $(LDFLAGS)

# Find only sources mathing the pattern
%: main = $(shell find $(SRC_DIRS) -mindepth 1 -maxdepth 1 -name 'main.c')
%: unity = $(shell find $(UNITY_DIRS) -name '*.c')
%: tests = $(shell find $(TEST_DIRS) -mindepth 2 -maxdepth 2 -iname '*'$@'*.c')
%: probs = $(shell find $(SRC_DIRS) -mindepth 2 -maxdepth 2 -iname '*'$@'*.c')
%: srcs = $(main) $(probs) $(tests) $(unity)
%: objs = $(patsubst %, $(BUILD_DIR)/%.o, $(srcs))
%: edit_defs = $(patsubst %, edit_defs_%, $(call test_prob, $(probs)))
%: setup $$(edit_defs) $$(objs) $(final)
	# Executing problems matching '$@'
	@$(final)
