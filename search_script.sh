#!/bin/bash

echo 'Go to the path'
cd $1
echo 'Search files...'
find . -name "*$2*">LR2.txt
