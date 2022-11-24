#!/bin/bash
for i in {0..999999}
do
   #if output empty send message and exit
   if [ "$(ls -A ./output/)" ]; then
     echo "new image added to 'output', save and delete this image if you want launch again..."
     exit 0
      #if output not empty try parse & interpret
	else
      echo "searching..."
      python3 parser.py $((RANDOM % 255)).$((RANDOM % 255)).$((RANDOM % 255)).$((RANDOM % 255))
      ./interpretator
     fi
done