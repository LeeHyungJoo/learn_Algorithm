#!/bin/bash

# Calculate half the number of files
file_count=$(git ls-files '**/*.cpp' '**/*.cs' | wc -l)

# Display values to verify calculations
echo "Total number of files: $file_count"

# Replace placeholder in README.md with the calculated value
sed -i -E "/Total Count of Solved/ s/$/ $half_file_count/" README.md
