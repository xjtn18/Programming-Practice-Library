CC=g++
CFLAGS=-Wall -c
EXEC=out

all: $(EXEC)

main.o: main.cpp
	$(CC) $< $(CFLAGS)

$(EXEC): main.o
	$(CC) $^ -o $@

.PHONY: run
run: $(EXEC)
	@ printf "\n"
	@ ./$(EXEC)

