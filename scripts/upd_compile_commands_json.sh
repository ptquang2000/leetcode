#!/bin/bash

if ! [ -x "$(command -v bear)" ]; then
  echo 'Error: bear is not installed.' >&2
  exit 1
fi

if ! [ -x "$(command -v jq)" ]; then
  echo 'Error: jq is not installed.' >&2
  exit 1
fi

scriptdir=$(dirname $0)
srcroot=$(dirname $scriptdir)
builddir=$srcroot/build
output=$srcroot/compile_commands.json

if [[ ! -e $builddir ]]; then
    mkdir -p $builddir
fi

modules="array_string binary_tree dsa graph heap linked_list map recursion stack"
for module in $modules; do
	bear --output $builddir/$module.json -- make $module
done

jq -s add $builddir/*.json > $output
sed -i 's/day[0-9]\+/day*/g' $output
