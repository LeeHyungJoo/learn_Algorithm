#!/bin/bash

# Calculate half the number of files
file_count=$(git ls-files | grep -E '\.(cpp|cs)$' | wc -l)

# Display values to verify calculations
echo "Total number of files: $file_count"

# Replace placeholder in README.md with the calculated value
sed -i -E "s|^(Total Count of Solved : )[0-9]+|\1$file_count|g" README.md
