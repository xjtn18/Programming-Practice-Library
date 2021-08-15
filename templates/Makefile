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
OBJDIR	:= .
# name of your final executable
EXEC 		:= out
# your C compiler
CC			:= g++
# compilation flags
LIBPATH	:= /Users/Jacob/dev/libs/mystd
CFLAGS	:= -I$(INCDIR) -I$(LIBPATH) \
				-std=c++17
# linker flags
LFLAGS	:= -L$(LIBPATH) -lmystd
#----------------------------------------------------------------#
#----------------------------------------------------------------#

OBJS 		:= $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(wildcard $(SRCDIR)/*.cpp))
HEADERS 	:= $(wildcard $(INCDIR)/*.hpp)


$(EXEC): $(OBJS)
	@ echo Linking dev build ...
	@ $(CC) $^ $(LFLAGS) -o $@
	@ echo Done.
	@ printf "\n"

%.o: $(SRCDIR)/%.cpp $(HEADERS) | $(OBJDIR)
	@ echo Compiling $< ...
	@ $(CC) $< -c $(CFLAGS) -o $@

# Runs the executable
run: $(EXEC)
	@ ./$(EXEC)

# Cleans all generated files
clean:
	@ rm -rf $(EXEC)
	@ rm -rf *.o

.PHONY: run clean


