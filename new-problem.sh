#!/bin/bash
while getopts n:l:d: flag
do
	case "${flag}" in
		n) pname=${OPTARG};;
		l) lang=${OPTARG};;
		d) diff=${OPTARG};;
	esac
done

dir="_${diff}/${pname}"

if [ -d $dir ];
then
	printf "Error: directory with this name already exists here.\n"
	exit 1
fi

if [ $lang = "python" ];
then
	mkdir $dir
	touch $dir/testcases.txt
	cp templates/python_template.txt $dir/sol.py
	printf "Created \'$pname\' python directory.\n"

elif [ $lang = "cpp" ];
then
	mkdir $dir
	cp templates/cpp_template.txt $dir/main.cpp
	printf "Created \'$pname\' cpp directory.\n"

elif [ $lang = "java" ];
then
	mkdir $dir
	cp templates/java_template.txt $dir/main.java
	printf "Created \'$pname\' java directory.\n"

else
	printf "Invalid / no template for language\n"
fi

sleep 1
