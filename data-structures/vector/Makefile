CC = g++
FLAGS = -std=c++11

all: test

run: test
	@rm -f *.o
	@./test.out

test: test.o
	@$(CC) $(FLAGS) test.o -o test.out

test.o: test.cpp vector.hpp ../../helpers/print.hpp
	@$(CC) $(FLAGS) -c  vector.hpp ../../helpers/print.hpp test.cpp

clean:
	@rm -f test.out
	@rm -f *.o
