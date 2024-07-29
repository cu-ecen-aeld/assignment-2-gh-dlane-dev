#!/bin/sh

if [ $# -eq 2 ]
then
	if [ -d "$1" ]
	then
		file_count=$(ls -Aq $1 | wc -l)
		matches_found=$(grep -r $2 $1 | wc -l)
		echo "The number of files are ${file_count} and the number of matching lines are ${matches_found}"
		exit 0
	else
		echo "source directory not found"
		exit 1
	fi
else
	echo "Incorrect number of arguments supplied"
	exit 1
fi
