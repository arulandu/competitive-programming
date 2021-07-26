# arg 1: template file
# arg 2+: file names without extension
template="${@:1:1}"
extension=".${template##*.}"
echo "Copy $template? Enter to continue. Ctrl+C to exit."
read -n 1
for i in "${@:2}"
do
    cp $template "${i}${extension}"
done
echo "Copied. Enter to exit."
read -n 1