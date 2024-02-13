#!/bin/bash

level=$1
path=$2

scp -P 4243 "$level"@localhost:/home/users/"$level"/"$level" "$path"