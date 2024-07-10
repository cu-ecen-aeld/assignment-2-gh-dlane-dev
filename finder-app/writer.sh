#1/bin/bash

if [ $# -eq 2 ]
then
	directory=$(dirname $1)
	mkdir -p ${directory}
	echo $2 > $1
	exit 0
else
	echo "Incorrect numberof parameters supplied"
	exit 1
fi
