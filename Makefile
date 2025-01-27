abs_srctree := $(dir $(realpath $(lastword $(MAKEFILE_LIST))))
srcroot := .
build_dir := $(srcroot)/build
config_dir := $(srcroot)/include/config
BUILD_CONFIG := $(srcroot)/.config

export srcroot abs_srctree build_dir config_dir BUILD_CONFIG

outdir := $(build_dir)/$(srcroot)/src

include $(srcroot)/scripts/Makefile.include

PHONY := all
all:

$(outdir)/built-in.a:
	$(MAKE) $(build)=src

PHONY += main
main: $(outdir)/built-in.a
	$(CC) $< -o $@

$(config_dir)/auto.conf: $(BUILD_CONFIG)
	$(MAKE) $(config)=src syncconfig

PHONY += prepare
prepare: $(config) ;

all: prepare main

PHONY += clean
clean:
	rm -rf $(config_dir) $(build_dir)

PHONY += prepare_config
prepare_config:
	mkdir -p $(config_dir) && touch $(BUILD_CONFIG)

generate_configs = $(addsuffix =y\\n, $(shell ls -1 $(config_dir) | grep "CONFIG_"))

real-goals := $(filter-out $(PHONY), $(MAKECMDGOALS))
this-target := $(firstword $(real-goals))
ifneq ($(filter-out $(this-target), $(real-goals)),)
$(error Run must contain only one target)
endif

ifneq ($(this-target),)
$(this-target): prepare_config
	$(MAKE) $(runtarget)=src $(this-target)
endif

.PHONY: $(PHONY)
