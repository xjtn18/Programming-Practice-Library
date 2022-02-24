##########################################################################
# Author: Jacob Nardone
# File Type: GNU Makefile
# Date Created: 4/9/2021
# Description: Makefile for Google Kickstart C++ problems.
##########################################################################

ifndef p:
	p := 1
endif

#----------------------------------------------------------------#
#----------------------------------------------------------------#
# name of dir that stores source files
SRCDIR	:= .
# name of dir that stores header files
INCDIR	:= .
# name of dir that stores object files
OBJDIR 	:= .
# name of your final executable
EXEC 		:= out
# your C compiler
CC			:= g++
# compilation flags
LIBPATH	:= /Users/Jacob/dev/Programming-Practice-Library/mystd
CFLAGS	:= -I$(INCDIR) -I$(LIBPATH) \
				-std=c++17
# linker flags
LFLAGS	:= -L$(LIBPATH) -lmystd
#----------------------------------------------------------------#
#----------------------------------------------------------------#


# Links object files and generates executable
$(EXEC):
	@ echo Linking executable ...
	@ $(CC) $(CFLAGS) $(LFLAGS) p$(p).cpp -o $@
	@ echo Done.
	@ printf "\n"

# Checks if needs to be rebuilt and runs the executable
runn: $(EXEC)
	@ ./$(EXEC)

run:
	@ make clean
	@ make runn

# Just runs the executable
runonly:
	@ ./$(EXEC)

# Cleans all generated files
clean:
	@ rm -f $(EXEC)

.PHONY: run clean



