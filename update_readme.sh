# Count the number of files
file_count=$(($(git ls-files | wc -l)) / 2)

# Replace placeholder in README.md with the file count
sed -i "s/{{FILE_COUNT}}/$file_count/g" README.md
