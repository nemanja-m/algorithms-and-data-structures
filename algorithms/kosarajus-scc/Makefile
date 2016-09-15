CC = g++
FLAGS = -std=c++11
DEPS = ../../data-structures/graph-representation/graph.hpp ../../helpers/print.hpp

all: test

run: test
	@rm -f *.o
	@./test.out

test: test.o
	@$(CC) $(FLAGS) test.o -o test.out

test.o: test.cpp scc.hpp $(DEPS)
	@$(CC) $(FLAGS) -c scc.hpp $(DEPS) test.cpp

clean:
	@rm -f test.out
	@rm -f *.o
