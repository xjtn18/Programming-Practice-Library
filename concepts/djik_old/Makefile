CC=g++
CFLAGS=-std=c++17 -Wc++17-extensions -Wall -c
EXEC=out

default: build

dijkstras.o: dijkstras.cpp
	$(CC) $< $(CFLAGS)

build: dijkstras.o
	$(CC) $< -o $(EXEC)

run: build
	@./$(EXEC) small.graph 0 0

