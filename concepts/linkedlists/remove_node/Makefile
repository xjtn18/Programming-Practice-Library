##########################################################################
# Author: Jacob Nardone
# File Type: GNU Makefile
# Date Created: 12/29/21
# Description: Simple Java Makefile for programming problems.
##########################################################################


Solution.class: main.java
	@echo Building class files...
	@javac \
		-d /Users/Jacob/dev/Programming-Practice-Library/myjavapkg/classes \
		main.java \
		/Users/Jacob/dev/Programming-Practice-Library/myjavapkg/myjava/LinkNode.java
	@printf "Done!\n\n"

run: Solution.class
	@java -cp /Users/Jacob/dev/Programming-Practice-Library/myjavapkg/classes Solution

runonly:
	@java -cp /Users/Jacob/dev/Programming-Practice-Library/myjavapkg/classes Solution

clean:
	rm -rf Solution.class
