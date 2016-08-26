CC = g++
FLAGS = -std=c++11

all: test

run: test
	@rm -f *.o
	./test.out

test: test.o helpers.o heap.hpp
	@$(CC) $(FLAGS) test.o helpers.o -o test.out

helpers.o: ../../helpers/helpers.cpp ../../helpers/helpers.hpp
	@$(CC) $(FLAGS) -c ../../helpers/helpers.cpp

test.o: test.cpp
	@$(CC) $(FLAGS) -c test.cpp

clean:
	@rm -f test.out
	@rm -f *.o
