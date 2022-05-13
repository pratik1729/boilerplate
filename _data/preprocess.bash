#!/bin/bash

for file in `ls *.md`; do
echo $file
python3 table_converter.py $file
done
