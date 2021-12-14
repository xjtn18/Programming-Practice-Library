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
# name of dir that stores object files
OBJDIR 	:= objs
# name of your final executable
EXEC 		:= out
# your C compiler
CC			:= g++
# compilation flags
CFLAGS	:= -std=c++17 -Wc++17-extensions -Wall \
				-I$(INCDIR) -I/Users/Jacob/dev/LeetCodeSolutions/mystd
# linking flags (libraries)
LFLAGS	:=
#----------------------------------------------------------------#
#----------------------------------------------------------------#

# creates string list of object files we need to create
OBJS 		:= $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(wildcard $(SRCDIR)/*.cpp))
# creates string list of all our header files
HEADERS 	:= $(wildcard $(INCDIR)/*.hpp)

# Links object files and generates executable
$(EXEC): $(OBJS)
	@echo Linking executable ...
	@$(CC) $^ $(LFLAGS) -o $@
	@echo Done.
	@printf "\n"

# Creates every object file we need in OBJS using corresponding source file + headers
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS) | $(OBJDIR)
	@echo Compiling $< ...
	@$(CC) $< -c $(CFLAGS) -o $@

# Builds the object file directory if not already there
$(OBJDIR):
	mkdir -p $@

# Runs the executable
run: $(EXEC)
	@ ./$(EXEC) $(g) $(s) $(bi)

# Cleans all generated files
clean:
	@ rm -rf $(EXEC) $(OBJDIR)

.PHONY: run clean


