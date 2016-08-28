CC = g++
FLAGS = -std=c++11

all: clean test coursera_test

test: test.o min_cut.o
	@$(CC) $(FLAGS) min_cut.o test.o -o test

test.o: test.cpp
	@$(CC) $(FLAGS) -c test.cpp

min_cut.o: min_cut.hpp min_cut.cpp graph.hpp
	@$(CC) $(FLAGS) -c  graph.hpp min_cut.cpp

coursera_test: coursera_test.o
	@$(CC) $(FLAGS) coursera_test.o min_cut.o -o coursera_test

coursera_test.o: coursera_test.cpp
	@$(CC) $(FLAGS) -c coursera_test.cpp

clean:
	@rm -f *.o test coursera_test
