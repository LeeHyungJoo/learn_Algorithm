# Count the number of files
file_count=$(git ls-files | wc -l)
half_file_count=$((file_count / 2))

# Replace placeholder in README.md with the file count
sed -i -E "s|^(Total Count of Solved : )[0-9]+|\1$half_file_count|g" README.md
