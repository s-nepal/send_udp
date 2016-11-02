# Makefile

CXX = g++
OFLAG = -O3

all: main

main:
	@$(CXX) -std=c++11 -o main main.cpp  $(OFLAG) -ltins

clean:
	rm -f main
	rm -f *.o