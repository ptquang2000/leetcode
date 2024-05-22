TARGET_EXEC := $(notdir $(shell pwd))

BUILD_DIR := ./build
SRC_DIRS := ./src

# Find all the C and C++ files we want to compile
# Note the single quotes around the * expressions. The shell will incorrectly expand these otherwise, but we want to send the * directly to the find command.
SRCS := $(shell find $(SRC_DIRS) -mindepth 1 -maxdepth 1 -name *.cpp -or -name *.c -or -name *.s)

# # Prepends BUILD_DIR and appends .o to every src file
# # As an example, ./your_dir/hello.cpp turns into ./build/./your_dir/hello.cpp.o
# OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

# Every folder in ./src will need to be passed to GCC so that it can find header files
INC_DIRS := $(shell find $(SRC_DIRS) -type d)
# Add a prefix to INC_DIRS. So moduleA would become -ImoduleA. GCC understands this -I flag
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

all::

# The -MMD and -MP flags together generate Makefiles for us!
# These files will have .d instead of .o as the output.
CPPFLAGS := $(INC_FLAGS) -MMD -MP

# # The final build step.
# $(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
# 	$(CXX) $(OBJS) -o $@ $(LDFLAGS)
# 

# # Build step for C++ source
# $(BUILD_DIR)/%.cpp.o: %.cpp
# 	mkdir -p $(dir $@)
# 	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

%: TOPICS = $(shell find $(SRC_DIRS) -mindepth 1 -maxdepth 1 -type d -iname *$@*)
%: PROBLEMS = $(shell find  $(SRC_DIRS) -iname *$@*.cpp -or -iname *$@*.c -or -iname *$@*.s)
%: SRCS += $(PROBLEMS) $(TOPICS)
%: OBJS = $(SRCS:%=$(BUILD_DIR)/%.o)
%: $(OBJS)
	# Step 1:
	@echo depends on: $(OBJS)

# Build step for C source
$(BUILD_DIR)/%.c.o:
	# Step 2:
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)
