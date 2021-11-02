#!/bin/bash
echo "Enter adress for search:"
read adress
echo "Enter pattern for search:"
read pattern
echo "Saved files:"
find $adress -type f -iname "*$pattern*" | tee list.txt
fi
