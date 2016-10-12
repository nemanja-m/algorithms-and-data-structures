CC = g++
FLAGS = -std=c++11

test: test.cpp two_sum.hpp
	@$(CC) $(FLAGS) test.cpp two_sum.hpp -o test.out
	@./test.out

coursera_test: coursera_test.cpp coursera.hpp
	@$(CC) $(FLAGS) coursera_test.cpp coursera.hpp -o coursera_test.out
	@./coursera_test.out

clean:
	@rm -f test.out coursera_test.out
