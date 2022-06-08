#!/bin/zsh

name=$1
lang=$2
diff=$3

if [ $lang = "sql" ]; then
	dir="_$diff/SQL/"
else
	dir="_$diff/$name"
	if [ -d $dir ]; then
		printf "Problem with this name & difficulty already exists.\n"
		return 1
	fi
	mkdir $dir
fi


if [ $lang = "cpp" ]; then
	cp -r templates/cpp/* $dir/
	printf "Created C++ problem at $dir\n"
	sleep 1
	cd $dir
	return 0
fi

if [ $lang = "python" ]; then
	cp -r templates/python/* $dir/
	printf "Created Python problem at $dir\n"
	sleep 1
	cd $dir
	return 0
fi

if [ $lang = "java" ]; then
	cp -r templates/java/* $dir/
	printf "Created Java problem at $dir\n"
	sleep 1
	cd $dir
	return 0
fi

if [ $lang = "sql" ]; then
	touch $dir/$name.sql
	printf "Created SQL problem at $dir\n"
	sleep 1
	cd $dir
	return 0
fi


