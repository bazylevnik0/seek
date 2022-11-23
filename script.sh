#!/bin/bash
for i in {0..999999}
do
   if [ "$(ls -A ./output/)" ]; then
     exit 0
	else
      python3 parser.py $((RANDOM % 255)).$((RANDOM % 255)).$((RANDOM % 255)).$((RANDOM % 255))
     ./interpretator
	fi
done