CC = g++
FLAGS = -std=c++11

all: test

run: test
	@rm -f *.o
	./test.out

test: test.o
	@$(CC) $(FLAGS) test.o -o test.out

test.o: test.cpp ../../helpers/print.hpp  heap.hpp
	@$(CC) $(FLAGS) -c test.cpp ../../helpers/print.hpp  heap.hpp

clean:
	@rm -f test.out
	@rm -f *.o
