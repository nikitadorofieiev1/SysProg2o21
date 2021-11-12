#!/bin/bash
echo Input the pattern:
read pattern
echo Input the dir:
read dir
if find $dir -maxdepth 1 -type f -name "*$pattern*"
then
find $dir -maxdepth 1 -type f -name "*$pattern*">test.txt
fi
