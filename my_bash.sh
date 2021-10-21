#!/bin/bash
# search for files with 'git' in it and put it into text file
adress="D:\Git"
find $adress -type f -iname "git*" | tee allgit.txt
fi
