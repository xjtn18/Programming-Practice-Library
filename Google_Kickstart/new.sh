#!/bin/zsh
emulate -LR zsh

dir=$1


if [ -d $dir ]; then
	printf "Directory with this name already exists.\n"
	return 1
fi

mkdir $dir

cp -r Kickstart_Template/Makefile $dir/
cp Kickstart_Template/template.cpp $dir/p1.cpp
cp Kickstart_Template/template.cpp $dir/p2.cpp
cp Kickstart_Template/template.cpp $dir/p3.cpp
cp Kickstart_Template/template.cpp $dir/p4.cpp
touch $dir/tests.txt
echo 1 >> $dir/tests.txt
printf "Created Kickstart directory '$dir'\n"
sleep 1
cd $dir

