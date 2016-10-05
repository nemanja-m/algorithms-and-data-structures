CC = g++
FLAGS = -std=c++11

run: main.o interpreter.o
	@$(CC) $(FLAGS) interpreter.o main.o -o evaluate

main.o: main.cpp convertor.hpp parser.hpp interpreter.hpp
	@$(CC) $(FLAGS) -c main.cpp convertor.hpp parser.hpp interpreter.hpp

interpreter.o: interpreter.hpp interpreter.cpp
	@$(CC) $(FLAGS) -c interpreter.cpp

clean:
	@rm -f evaluate
	@rm -f *.o
