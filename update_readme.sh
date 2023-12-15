#!/bin/bash

# Calculate half the number of files
file_count=$(git ls-files | wc -l)
half_file_count=$((file_count / 2))

# Display values to verify calculations
echo "Total number of files: $file_count"
echo "Half the number of files: $half_file_count"

# Replace placeholder in README.md with the calculated value
sed -i -E "s|^(Total Count of Solved : )[0-9]+|\1$half_file_count|g" README.md
