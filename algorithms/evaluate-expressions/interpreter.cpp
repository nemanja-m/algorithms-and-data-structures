#include "interpreter.hpp"
#include "string"
#include "iostream"

namespace Interpreter {

  namespace {
    // Prints greeting message and info about
    // evaluator
    void info() {
      std::cout << "\n-- Algebraic expresion evaluator --\n\n";
      std::cout << " --------------------------------------\n";
      std::cout << "| Supported operations: +, -, /, *, () |\n";
      std::cout << "| Enter 'exit' for exit                |\n";
      std::cout << " --------------------------------------\n\n";
    }

    // Reads from standard input
    std::string read() {
      std::cout << ">>> ";

      std::string ret;
      std::cin >> ret;

      return ret;
    }

    // Evaluates given expression
    double evaluate(std::string &expression) {
      if (expression == "exit")
        exit(0);

      return 42;
    }

    // Prints content to standard output
    template <class Object> void print(const Object &content) {
      std::cout << ">>> " << content << std::endl;
    }

  }

  void start() {
    info();

    while (true) {
      std::string expression = read();

      double result = evaluate(expression);

      print(result);
    }
  }
}