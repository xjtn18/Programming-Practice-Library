CC=g++
CFLAGS=-std=c++17 -Wc++17-extensions -Wall -c
EXEC=out

$(EXEC): dijkstras.o
	$(CC) $< -o $(EXEC)

dijkstras.o: dijkstras.cpp
	$(CC) $< $(CFLAGS)

run: $(EXEC)
	@./$(EXEC) small.graph 0 0

