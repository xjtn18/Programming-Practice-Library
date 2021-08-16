#!/bin/zsh
emulate -LR zsh

name=$1
lang=$2
diff=$3

dir="_$diff/$name"

if [ -d $dir ]; then
	printf "Problem with this name already exists.\n"
	return 1
fi

mkdir $dir

if [ $lang = "cpp" ]; then
	cp templates/cpp_template.txt $dir/main.cpp
	cp templates/makefile_template.txt $dir/Makefile
	printf "Created C++ problem at $dir\n"
	sleep 1
	cd $dir
	return 0
fi

if [ $lang = "python" ]; then
	cp templates/python_template.txt $dir/main.py
	printf "Created Python problem at $dir\n"
	sleep 1
	cd $dir
	return 0
fi

if [ $lang = "java" ]; then
	cp templates/java_template.txt $dir/main.java
	printf "Created Java problem at $dir\n"
	sleep 1
	cd $dir
	return 0
fi


