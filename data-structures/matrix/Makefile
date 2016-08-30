CC = g++
FLAGS = -std=c++11

all: test

run: test
	@rm -f *.o
	@./test.out

test: test.o matrix.hpp
	@$(CC) $(FLAGS) test.o -o test.out

test.o: test.cpp
	@$(CC) $(FLAGS) -c test.cpp

clean:
	@rm -f test.out
	@rm -f *.o
