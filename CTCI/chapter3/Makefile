##########################################################################
# Author: Jacob Nardone
# File Type: GNU Makefile
# Date Created: 2/22/22
# Description: Simple Java Makefile
##########################################################################

#----------------------------------------------------------------#
#--------------------- Project Specifics ------------------------#
# Path to your program start class relative to source directory
mainclass := Chapter_3
# Full path to you java source code / packages
srcdir := .
# Name of the directory storing your class files
bindir := target
# Path(s) to all class files needed to compile and run
clspth := target:$(shell git rev-parse --show-toplevel)/myjavapkg/classes
#----------------------------------------------------------------#
#----------------------------------------------------------------#

modlist := $(bindir)/modlist
# Recursive wildcard function - leave as is.
rwildcard = $(foreach d,$(wildcard $(1:=/*)), $(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))
sources = $(call rwildcard, $(srcdir), *.java)

.PHONY: run runonly clean

# compares timestamps of the dummy file (modlist) with each source file
$(modlist): $(sources) | $(bindir)
	@ echo Compiling $(notdir $?) ...
	@ javac -d $(bindir) -classpath $(clspth) $?
	@ printf "Done!\n\n"
	@ touch $@

run: $(modlist)
	@ make runonly --no-print-directory

runonly:
	@ java -classpath $(clspth) $(mainclass)

$(bindir):
	@ mkdir $@

clean:
	@ rm -rf $(bindir)


