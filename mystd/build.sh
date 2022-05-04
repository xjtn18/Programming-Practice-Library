#!/bin/bash

g++ -std=c++17 -o mystd.o -c mystd.cpp -I.
ar rcs libmystd.a mystd.o

