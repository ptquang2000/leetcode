day_dirs := $(sort $(shell find $(SRC_DIRS) -type d -name 'day*'))
day_num := $(subst day,,$(lastword $(notdir $(day_dirs))))
ifeq ($(day_num),)
dir_name := $(SRC_DIRS)/day1
else
dir_name := $(SRC_DIRS)/$(addprefix day, $(shell expr $(day_num) + 1))
endif

DSA_TOPICS := ArrayString \
	      TwoPointers
ArrayString := merge \
	       removeElement
TwoPointers := isPalindrome

get_srcs = $(patsubst %, $(1)/%.c, $(value $(notdir $(1))))
NEW_SRCS := $(foreach topic, $(DSA_TOPICS), $(call get_srcs, $(dir_name)/$(topic)))

include $(SCRIPT_DIRS)/data.mk

$(NEW_SRCS): def_func = $(notdir $(basename $@))
$(NEW_SRCS):
	# Generating $@
	@mkdir -p $(dir $@)
	@touch $@
	@echo '#include "defs.h"' >> $@
	@echo '' >> $@
	@echo '$(value $(def_func))' >> $@
	@echo '}' >> $@

.PHONY: generate
generate: $(NEW_SRCS)
