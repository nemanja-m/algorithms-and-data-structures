CC = g++
FLAGS = -std=c++11

all: test

run: test
	@rm -f *.o
	@./test.out

test: test.o helpers.o
	@$(CC) $(FLAGS) helpers.o test.o -o test.out

test.o: test.cpp bsort.hpp
	@$(CC) $(FLAGS) -c  bsort.hpp test.cpp

helpers.o: ../../helpers/helpers.hpp ../../helpers/helpers.cpp
	@$(CC) $(FLAGS) -c ../../helpers/helpers.cpp

clean:
	@rm -f test.out
	@rm -f *.o
