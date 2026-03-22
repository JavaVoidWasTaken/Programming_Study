#!/bin/bash

if [ $# -lt 2 ]; then
  echo "Not enough arguments!"
else
  if [ $1 -gt $2 ]; then
    echo "$1 is greater than $2"
  else
    echo "$2 is greater than $1"
  fi
fi
