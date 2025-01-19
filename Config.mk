pattern := $(strip $(test))

CONFIG_UTILS:=y

hit_prob = $(shell find $(1) -name '*.c')
ifeq ($(call hit_prob,"./src/array_string/"),)
	CONFIG_ARRAY_STRING:=y
endif
ifeq ($(call hit_prob,"./src/linked_list/"),)
	CONFIG_LINKED_LIST:=y
endif
ifeq ($(call hit_prob,"./src/queue/"),)
	CONFIG_QUEUE:=y
endif
ifeq ($(call hit_prob,"./src/stack/"),)
	CONFIG_STACK:=y
endif
ifeq ($(call hit_prob,"./src/recursion/"),)
	CONFIG_RECURSION:=y
endif
ifeq ($(call hit_prob,"./src/binary_tree/"),)
	CONFIG_BINARY_TREE:=y
endif

hit_topic = $(shell find $(1) -maxdepth 1 -type d -iname '*$(pattern)*')
ifeq ($(call hit_topic,"./src/"),array_string)
	CONFIG_ARRAY_STRING:=y
endif
ifeq ($(call hit_topic,"./src/"),linked_list)
	CONFIG_LINKED_LIST:=y
endif
ifeq ($(call hit_topic,"./src/"),queue)
	CONFIG_QUEUE:=y
endif
ifeq ($(call hit_topic,"./src/"),stack)
	CONFIG_STACK:=y
endif
ifeq ($(call hit_topic,"./src/"),recursion)
	CONFIG_RECURSION:=y
endif
ifeq ($(call hit_topic,"./src/"),binary_tree)
	CONFIG_BINARY_TREE:=y
endif

