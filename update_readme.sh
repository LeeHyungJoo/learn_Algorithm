#!/bin/bash

# Count the number of .cpp and .cs files
file_count=$(git ls-files '**/*.cpp' '**/*.cs' | wc -l)

# Display value to verify the calculation
echo "Total number of .cpp and .cs files: $file_count"

# Update file count after "Total Count of Solved" in README.md
sed -E "s/(Total Count of Solved: )[0-9]+/\1$file_count/" README.md
