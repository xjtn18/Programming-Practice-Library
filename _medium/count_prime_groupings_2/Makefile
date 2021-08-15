##########################################################################
# Author: Jacob Nardone
# File Type: GNU Makefile
# Date Created: 4/9/2021
# Description: Flexible C makefile for ranging project file structures.
##########################################################################

# FILL IN THE SECTION BELOW #
#----------------------------------------------------------------#
#----------------------------------------------------------------#
# name of dir that stores source files
SRCDIR	:= .
# name of dir that stores header files
INCDIR	:= .
# name of your final executable
EXEC 		:= out
# your C compiler
CC			:= g++
# compilation flags
CFLAGS	:= -I$(INCDIR) -I/Users/Jacob/dev/LeetCodeSolutions/ \
				-std=c++17
#----------------------------------------------------------------#
#----------------------------------------------------------------#

# creates string list of all our header files
HEADERS 	:= $(wildcard $(INCDIR)/*.hpp)

# Links object files and generates executable
$(EXEC): $(HEADERS)
	@$(CC) main.cpp $^ $(CFLAGS) -o $@

# Runs the executable
run: $(EXEC)
	@ ./$(EXEC)

# Cleans all generated files
clean:
	@ rm -rf $(EXEC)

.PHONY: run clean


