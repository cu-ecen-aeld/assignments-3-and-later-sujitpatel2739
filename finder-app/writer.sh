#!/bin/sh
# Assignment 1
# Author: Sujit Kumar Patel

if [ $# -ne 2 ]
then
    echo "Error: Two arguments required."
    exit 1
fi

writefile=$1
writestr=$2

# Create parent directory path if it doesn't exist
mkdir -p "$(dirname "$writefile")" || {
    echo "Error: Could not create directory path."
    exit 1
}

# Create/overwrite file with writestr
echo "$writestr" > "$writefile" || {
    echo "Error: Could not create file."
    exit 1
}
