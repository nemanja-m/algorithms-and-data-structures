CC = g++
FLAGS = -std=c++11

run: main.o interpreter.o evaluator.o parser.o
	@$(CC) $(FLAGS) interpreter.o parser.o main.o evaluator.o -o evaluate

main.o: main.cpp interpreter.hpp
	@$(CC) $(FLAGS) -c main.cpp interpreter.hpp

interpreter.o: interpreter.hpp interpreter.cpp evaluator.hpp parser.hpp
	@$(CC) $(FLAGS) -c interpreter.cpp evaluator.hpp parser.hpp

evaluator.o: evaluator.cpp evaluator.hpp
	@$(CC) $(FLAGS) -c evaluator.cpp

parser.o: parser.cpp parser.hpp
	@$(CC) $(FLAGS) -c parser.cpp

clean:
	@rm -f evaluate
	@rm -f *.o
