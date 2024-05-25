TARGET_EXEC := $(notdir $(shell pwd))

BUILD_DIR := ./build
SRC_DIRS := ./src

# Find all the C and C++ files we want to compile
# Note the single quotes around the * expressions. The shell will incorrectly expand these otherwise, but we want to send the * directly to the find command.
SUBDIRS := $(shell find $(SRC_DIRS) -mindepth 1 -maxdepth 1 -type d)

# Every folder in ./src will need to be passed to GCC so that it can find header files
INC_DIRS := $(shell find $(SRC_DIRS) -type d)
# Add a prefix to INC_DIRS. So moduleA would become -ImoduleA. GCC understands this -I flag
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

.PHONY: Makefile

.PHONY: clear_all
clear_all:
	@echo Clearing all problems

.PHONY: gen_all
gen_all:
	@echo Generating all problems

.PHONY: clean
clean:
	@rm -rf $(BUILD_DIR)

# Build step for C source
$(BUILD_DIR)/%.c.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

.SECONDEXPANSION:
final := $(BUILD_DIR)/$(TARGET_EXEC)
$(final): objs = $(shell find $(BUILD_DIR) -name '*.o')
$(final): $$(objs)
	@$(CXX) $^ -o $@ $(LDFLAGS)

%: probs = $(shell find $(SRC_DIRS) -iname '*'$@'*.c' -or -name 'main.c')
%: objs = $(patsubst %, $(BUILD_DIR)/%.o, $(probs))
%: clean $$(objs) $(final)
	# Executing problems match '$@'
	@$(final)
