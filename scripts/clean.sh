find . -regex ".*\.\(exe\|in\|out\)" -type f
echo "Delete? Enter for yes. Ctrl+C to exit."
read -n 1
find . -regex ".*\.\(exe\|in\|out\)" -type f -delete
echo "Successfully deleted. Enter to exit."
read -n 1