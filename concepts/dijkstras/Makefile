
all: build run

build: dijkstras.cpp
	g++ $< -o out

run: out
	@./out large.graph 5 0

