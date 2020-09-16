#!/bin/bash
while getopts n:l: flag
do
	case "${flag}" in
		n) pname=${OPTARG};;
		l) lang=${OPTARG};;
	esac
done

if [ -d $pname ];
then
	printf "Error: directory with this name already exists.\n"
	exit 1
fi

if [ "$lang" = "python" ];
then
	mkdir $pname
	touch $pname/testcases.txt
	cp templates/python_template.txt $pname/sol.py
	printf "Created \'$pname\' python directory.\n"

elif [ $lang = "cpp" ];
then
	mkdir $pname
	cp templates/cpp_template.txt $pname/main.cpp
	printf "Created \'$pname\' cpp directory.\n"

elif [ $lang = "java" ];
then
	mkdir $pname
	cp templates/java_template.txt $pname/main.java
	printf "Created \'$pname\' java directory.\n"

else
	printf "Invalid / unsupported template language\n"
fi

