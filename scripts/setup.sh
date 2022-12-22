#/bin/bash

# arg 1: template file
# arg 2+: file names without extension
read -p "Template: " template
read -p "Files: " filestr
IFS=' ' read -a files <<< "$filestr"
extension=".${template##*.}"
for i in "${files[@]}"
do
    cp $template "${i}${extension}"
done
echo "Copied."