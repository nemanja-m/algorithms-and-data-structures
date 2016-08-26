CC = g++
FLAGS = -std=c++11

all: merge

run: merge
	@rm -f *.o
	@./merge.out $(ARRAYS)

merge: merge.o helpers.o utils.o
	@$(CC) $(FLAGS) merge.o helpers.o utils.o -o merge.out

helpers.o: ../../helpers/helpers.cpp ../../helpers/helpers.hpp
	@$(CC) $(FLAGS) -c ../../helpers/helpers.cpp

merge.o: merge.cpp
	@$(CC) $(FLAGS) -c merge.cpp

utils.o: utils.hpp utils.cpp
	@$(CC) $(FLAGS) -c utils.cpp

clean:
	@rm merge.out
	@rm -f *.o
