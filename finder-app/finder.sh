#!/bin/sh
# Tester script for assignment 1
# Author: Sujit Kumar Patel

filesdir=$1
searchstr=$2

if [ $# != 2 ]
then
    echo "Arguments given must be 2!"
    exit 1
fi

if [ ! -d "$filesdir" ]
then
    echo "${filesdir} is not a directory!"
    exit 1
fi

nfiles=$(find "$filesdir" -type f | wc -l)
nlines=$(grep -r "$searchstr" "$filesdir" | wc -l)

echo "The number of files are ${nfiles} and the number of matching lines are ${nlines}"
