##########################################################################
# Author: Jacob Nardone
# File Type: GNU Makefile
# Date Created: 12/29/21
# Description: Simple Java Makefile for programming problems.
##########################################################################

CLSPATH := /Users/Jacob/dev/Programming-Practice-Library/myjavapkg/classes

Solution.class: main.java
	@echo Building class files...
	@javac \
		-d $(CLSPATH) \
		-cp $(CLSPATH) \
		main.java
	@printf "Done!\n\n"

run: Solution.class
	@java -cp $(CLSPATH) Solution

runonly:
	@java -cp $(CLSPATH) Solution

clean:
	rm -rf $(CLSPATH)/Solution.class
