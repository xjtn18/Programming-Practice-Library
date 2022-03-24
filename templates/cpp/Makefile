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
OBJDIR 	:= .
# name of your final executable
EXEC 		:= out
# your C compiler
CC			:= g++
# compilation flags
LIBPATH	:= $(shell git rev-parse --show-toplevel)/mystd
CFLAGS	:= -I$(INCDIR) -I$(LIBPATH) \
				-std=c++17
# linker flags
LFLAGS	:= -L$(LIBPATH) -lmystd
#----------------------------------------------------------------#
#----------------------------------------------------------------#

# creates string list of object files we need to create
OBJS 		:= $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(wildcard $(SRCDIR)/*.cpp))
# creates string list of all our header files
HEADERS 	:= $(wildcard $(INCDIR)/*.hpp)

.PHONY: run runonly clean


# Links object files and generates executable
$(EXEC): $(OBJS)
	@echo Linking executable ...
	@$(CC) $^ $(LFLAGS) -o $@
	@rm -rf $(OBJS)
	@echo Done.
	@printf "\n"

# Creates every object file we need in OBJS using corresponding source file + headers
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS) | $(OBJDIR)
	@echo Compiling $< ...
	@$(CC) $< -c $(CFLAGS) -o $@

# Builds the object file directory if not already there
$(OBJDIR):
	mkdir -p $@

# Checks if needs to be rebuilt and runs the executable
run: $(EXEC)
	@make --no-print-directory runonly

# Just runs the executable
runonly:
	@ ./$(EXEC)

# Cleans all generated files
clean:
	@ rm -rf $(EXEC)




