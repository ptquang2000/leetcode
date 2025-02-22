## How to run testcase

First generate a day directory where you can solve a problem at with:

```sh
make generate
```

Then this command to run that problem's testcases:

```sh
make `problem name`
```

Note: This will execute all problems that match the name with wildcard. (It is `ls *name*.c`)

#### Unittest

```sh
make unittest test=`module name`
```

#### Update compile_commands.json

This requires `jq` and `bear` installed.

```sh
sh scripts/upd_compile_commands_json.sh
```
