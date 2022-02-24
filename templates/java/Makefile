##########################################################################
# Author: Jacob Nardone
# File Type: GNU Makefile
# Date Created: 2/22/22
# Description: Simple Java Makefile
##########################################################################

mylib := $(shell git rev-parse --show-toplevel)/myjavapkg/classes

Solution.class: Solution.java
	@echo Building class files...
	@javac -d $(mylib) -classpath $(mylib) Solution.java # writing class files to same directory as lib classes.
	@printf "Done!\n\n"

run: Solution.class
	@make runonly

runonly:
	@java -classpath $(mylib) Solution # all classes we need will be contained in $(mylib) directory.

clean:
	rm -rf Solution.class

