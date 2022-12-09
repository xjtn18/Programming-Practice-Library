##########################################################################
# Author: Jacob Nardone
# File Type: GNU Makefile
# Date Created: 4/9/2021
# Description: Flexible C makefile for ranging project file structures.
##########################################################################

# Set the default problem number
ifndef d:
	d := 1
endif

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
EXEC 		:= $(d).exe
# your C compiler
CC			:= "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\Llvm\bin\clang++.exe"
# compilation flags
LIBPATH	:= $(shell git rev-parse --show-toplevel)/mystd
CFLAGS	:= -I$(INCDIR) -I$(LIBPATH) \
				-std=c++17 -Wfatal-errors
# linker flags
LFLAGS	:= -L$(LIBPATH) -llibmystd
#----------------------------------------------------------------#
#----------------------------------------------------------------#

# creates string list of object files we need to create
OBJS 		:= $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)\\%.o, $(wildcard $(SRCDIR)/$(d).cpp))
# creates string list of all our header files
HEADERS 	:= $(wildcard $(INCDIR)/*.hpp)

.PHONY: run runonly clean


# Links object files and generates executable
$(EXEC): $(OBJS)
	@ echo Linking executable ...
	@ $(CC) $^ $(LFLAGS) -o $@
	@ del $(OBJS)
	@ echo Done. && echo.

# Creates every object file we need in OBJS using corresponding source file + headers
$(OBJDIR)\\%.o: $(SRCDIR)/$(d).cpp $(HEADERS) | $(OBJDIR)
	@ echo Compiling $< ...
	@ $(CC) $< -c $(CFLAGS) -o $@

# Builds the object file directory if not already there
$(OBJDIR):
	mkdir $@

# Checks if needs to be rebuilt and runs the executable
run: $(EXEC)
	@ make --no-print-directory runonly

# Just runs the executable
runonly:
	@ $(EXEC)

input/$(d).input:
	@ type nul > input/$(d).input

$(d).cpp:
	@ copy template.cpp $(d).cpp

new: $(d).cpp input/$(d).input

# Cleans all generated files
clean:
	@ del *.exe




