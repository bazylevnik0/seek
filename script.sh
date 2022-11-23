#!/bin/bash
for i in {0..999999}
do
   python3 parser.py $((RANDOM % 255)).$((RANDOM % 255)).$((RANDOM % 255)).$((RANDOM % 255))
   ./interpretator
done