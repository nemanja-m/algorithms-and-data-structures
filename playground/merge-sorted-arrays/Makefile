CC = g++
FLAGS = -std=c++11

all: merge

run: merge
	@rm -f *.o
	@./merge.out $(ARRAYS)

merge: merge.o utils.o
	@$(CC) $(FLAGS) merge.o utils.o -o merge.out

merge.o: merge.cpp
	@$(CC) $(FLAGS) -c merge.cpp

utils.o: utils.hpp utils.cpp ../../helpers/print.hpp
	@$(CC) $(FLAGS) -c utils.cpp ../../helpers/print.hpp

clean:
	@rm merge.out
	@rm -f *.o
