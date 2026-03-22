#!/bin/bash

if [ $# -lt 1 ]; then
  echo "Not enough arguments!"
  exit 1
else
  if [ -d ./$1 ]; then
    echo "The directory exists."
  elif [ -e ./$1 ]; then
    echo "The file exists."
  else
    echo "The object does not exist."
    exit 1
  fi
fi

# If the object exists, print the permissions.
if [ -r ./$1 ]; then
  echo "You have a read permission."
else
  echo "You do not have a read permission."
fi
if [ -w ./$1 ]; then
  echo "You have a write permission."
else
  echo "You do not have a write permission."
fi
if [ -x ./$1 ]; then
  echo "You have a execute permission."
else
  echo "You do not have a execute permission."
fi
