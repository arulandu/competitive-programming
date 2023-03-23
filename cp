#!/bin/bash

setup () {
  read -p "Template: " template
  read -p "Files: " filestr
  IFS=' ' read -a files <<< "$filestr"
  extension=".${template##*.}"
  for i in "${files[@]}"
  do
      cp $template "${i}${extension}"
  done
  echo "Copied."
}

cleanup () {
  read -p "Clean up directory? (y/n): " clean
  if [ "${clean:0:1}" = "y" ] || [ "${clean:0:1}" = "Y" ]
  then
    find $1 -regex ".*\.\(exe\|in\|out\)" -type f -delete
  fi

  read -p "Prefix: " prefix
  if [ ${#prefix} -gt 0 ]
  then
    for i in *; do mv "$i" $prefix"$i"; done
  else
    read -p "Rename files? (y/n): " rename
    if [ "${rename:0:1}" = "y" ] || [ "${rename:0:1}" = "Y" ]
    then
      for i in *;
      do
        extension="${i##*.}"
        fn="${i%.*}"
        read -p "$fn -> " name
        mv "$i" "$name.$extension" 
      done
    fi
  fi

  read -p "Add metadata? (y/n): " meta
  if [ "${meta:0:1}" = "y" ] || [ "${meta:0:1}" = "Y" ]
  then
    read -p "Contest Name: " contest
    for i in *;
    do
      read -p "Problem Name ($i): " problem
      sed -i "1i/*\nContest: ${contest} \nProblem: ${problem}\n*/" "$i"
    done
  fi
  echo "Exited."
}

if [ "$1" = "setup" ]; then
  setup
elif [ "$1" = "cleanup" ]; then
  cleanup
else
  if [ "$1" != "-h" ] && [ "$1" != "" ]; then
    echo "'$1' is not a valid sub-command."
    echo ""
  fi

  echo "A command-line competitive programming assistant."
  echo ""
  echo "Usage: cp [subcommands]"
  echo "  cp setup"
  echo "  cp cleanup"
  echo "  cp -h"
  echo ""
  echo "Subcommands:"
  echo "  setup   Prepare directory for contest."
  echo "  cleanup Process directory after contest."
  echo ""
  echo "Options:"
  echo "  -h      Show this screen."
  echo ""
fi
