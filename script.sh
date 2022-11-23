#!/bin/bash
for i in {0..999999}
do
   if [ "$(ls -A ./output/)" ]; then
     echo "new image added to 'output', save and delete this image if you want launch again..."
     exit 0
	else
      python3 parser.py $((RANDOM % 255)).$((RANDOM % 255)).$((RANDOM % 255)).$((RANDOM % 255))
      ./interpretator
	fi
done