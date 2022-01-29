##########################################################################
# Author: Jacob Nardone
# File Type: GNU Makefile
# Date Created: 12/29/21
# Description: Simple Java Makefile for programming problems.
##########################################################################

CLSNAME := Chapter_2
CLSPATH := /Users/Jacob/dev/Programming-Practice-Library/myjavapkg/classes

$(CLSNAME).class: main.java
	@echo Building class files...
	@javac \
		-d $(CLSPATH) \
		-cp $(CLSPATH) \
		main.java
	@printf "Done!\n\n"

run: $(CLSNAME).class
	@java -cp $(CLSPATH) $(CLSNAME)

runonly:
	@java -cp $(CLSPATH) $(CLSNAME)

clean:
	rm -rf $(CLSPATH)/$(CLSNAME).class
