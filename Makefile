TARGET_EXEC := $(notdir $(shell pwd))

BUILD_DIR := ./build
SRC_DIRS := ./src
ALL_TOPIC_DIRS := $(shell find $(SRC_DIRS) -mindepth 1 -maxdepth 1 -type d)
PROJ_SRCS := $(shell find $(SRC_DIRS) -maxdepth 1 -name '*.c')
MAIN_FILE := $(SRC_DIRS)/main.c

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))
CPPFLAGS := $(INC_FLAGS) -MMD -MP

day_num := $(words $(shell find ./ -maxdepth 1 -type d -name 'day*'))
ifneq ($(day_num),0)
day_dir := ./$(addprefix day, $(shell expr $(day_num)))
endif

.PHONY: main
pattern := $(strip $(test))
ifeq (${pattern},)
find_srcs = $(shell find $(1) -name '*.c')
prob_srcs := $(call find_srcs, $(day_dir))
proj_srcs := $(call find_srcs, $(SRC_DIRS))
else
find_topics = $(shell find $(1) -maxdepth 1 -type d -iname '*$(pattern)*')
topic_dirs := $(call find_topics, $(SRC_DIRS))
ifeq ($(topic_dirs),)
find_srcs = $(shell find $(1) -mindepth 2 -iname '*$(pattern)*.c')
else
find_srcs = $(shell find $(addprefix $(1)/, $(notdir $(topic_dirs))) -name '*.c')
endif
prob_srcs := $(call find_srcs, $(day_dir))
proj_srcs := $(call find_srcs, $(SRC_DIRS))
proj_srcs += $(PROJ_SRCS)
endif

PCH := $(SRC_DIRS)/pch.h
GCH := $(patsubst %, $(BUILD_DIR)/%.gch, $(PCH))
SRCS := $(prob_srcs) $(proj_srcs)
OBJS := $(patsubst %, $(BUILD_DIR)/%.o, $(SRCS))

ifneq ($(day_dir),)
main: setup $(BUILD_DIR)/$(TARGET_EXEC)
	@$(BUILD_DIR)/$(TARGET_EXEC)
else
main:
	@echo You need to run 'make generate' first
endif

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	@$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(GCH): $(PCH)
	@mkdir -p $(dir $@)
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/$(SRC_DIRS)/%.c.o: $(SRC_DIRS)/%.c $(GCH) 
	# Compiling $<
	@mkdir -p $(dir $@)
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/$(day_dir)/%.c.o: $(day_dir)/%.c $(GCH) 
	# Compiling $<
	@mkdir -p $(dir $@)
	@$(CC) $(CPPFLAGS) $(CFLAGS) -include $(PCH) -c $< -o $@


.PHONY: setup

all_topics := $(foreach topic, $(ALL_TOPIC_DIRS), $(notdir $(topic))/$(notdir $(topic)))
format_header = $(patsubst %,#include "%.h"\n, $(1))
include_headers := $(foreach header, $(all_topics), $(call format_header, $(header)))

get_prob_name = $(notdir $(realpath $(dir $(1))))_$(notdir $(basename $(1)))
prob_names := $(foreach problem, $(prob_srcs), $(call get_prob_name, $(problem)))
format_funcs = $(patsubst %, test_%\(\)\;\n, $(1))
test_funcs := $(foreach prob_name, $(prob_names), $(call format_funcs, $(prob_name)))

setup:
ifneq ($(include_headers),)
	@echo -e '$(include_headers)' > $(MAIN_FILE)
endif
	@echo -e 'int main() \n{' >> $(MAIN_FILE)
	@sed -i '/{/a }' $(MAIN_FILE)
ifneq ($(test_funcs),)
	@sed -i '/}/i\ $(test_funcs)' $(MAIN_FILE)
endif


.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
	rm -rf ./day*
	rm -f $(MAIN_FILE)

# Including .d makefiles generated from compiler
DEPS := $(OBJS:.o=.d)
-include $(DEPS)


.PHONY: generate
ALL_PROB_SRCS := $(foreach topic_dir, $(ALL_TOPIC_DIRS), $(shell find $(topic_dir) -name '*.c'))
NEW_DAY := ./$(addprefix day, $(shell expr $(day_num) + 1))
NEW_PROB_SRCS := $(patsubst $(SRC_DIRS)%, $(NEW_DAY)%, $(ALL_PROB_SRCS))

$(NEW_PROB_SRCS): prob_src = $(patsubst $(NEW_DAY)%, $(SRC_DIRS)%, ./$@)
$(NEW_PROB_SRCS): func_dec = $(shell awk '/Declaration/{getline; print}' $(prob_src))
$(NEW_PROB_SRCS): func_def = $(patsubst %;, %\n{, $(func_dec))
$(NEW_PROB_SRCS):
	# Generating $@
	@mkdir -p $(dir $@)
	@touch $@
	@echo -e '$(func_def)' >> $@
	@echo -e '}' >> $@

generate: $(NEW_PROB_SRCS) setup
