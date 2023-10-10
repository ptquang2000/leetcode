@echo off

call docker build --tag leetcode .
call docker container run --name leetcode -v %cd%:/leetcode -it leetcode bash