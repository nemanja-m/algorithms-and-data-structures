CC = g++
FLAGS = -std=c++11

all: test

run: test
	@rm -f *.o
	@./test.out

test: test.o min_cut.o
	@$(CC) $(FLAGS) min_cut.o test.o -o test.out

test.o: test.cpp
	@$(CC) $(FLAGS) -c test.cpp

min_cut.o: min_cut.hpp min_cut.cpp graph.hpp
	@$(CC) $(FLAGS) -c  graph.hpp min_cut.cpp

clean:
	@rm -f test.out
	@rm -f *.o
