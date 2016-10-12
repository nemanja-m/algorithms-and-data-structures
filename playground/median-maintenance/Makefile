CC = g++
FLAGS = -std=c++11

run: test

test: medians.cpp heap.hpp
	@$(CC) $(FLAGS) medians.cpp heap.hpp -o test.out
	@./test.out

clean:
	@rm -f test.out
