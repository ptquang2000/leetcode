#
# Makefile for src
#

ifneq ($(ENABLE_UNITTEST),1)
obj-y += main.o
endif

obj-y += pch.gch

subdir-$(CONFIG_UTILS_TEST) += utils

subdir-$(CONFIG_DSA) += dsa
subdir-$(CONFIG_ARRAY_STRING) += array_string
subdir-$(CONFIG_LINKED_LIST) += linked_list
subdir-$(CONFIG_STACK) += stack
subdir-$(CONFIG_RECURSION) += recursion
subdir-$(CONFIG_BINARY_TREE) += binary_tree
subdir-$(CONFIG_QUEUE) += queue
subdir-$(CONFIG_HEAP) += heap
subdir-$(CONFIG_GRAPH) += graph
subdir-$(CONFIG_MAP) += map
