#!/bin/bash

# Count the number of .cpp and .cs files
file_count=$(git ls-files *.cpp *.cs | wc -l)

# Display value to verify the calculation
echo "Total number of .cpp and .cs files: $file_count"

# Update file count after "Total Count of Solved" in README.md
awk -v count="$file_count" '/Total Count of Solved : / { sub(/[0-9]+/, count); } 1' README.md > temp && mv temp README.md
