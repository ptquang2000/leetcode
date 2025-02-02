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

First add .config file, then add the required configs for your desired test module. After that run this commands.

```sh
make -e ENABLE_UNITTEST=1
```
