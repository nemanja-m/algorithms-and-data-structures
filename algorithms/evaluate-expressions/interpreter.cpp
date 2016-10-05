#include "interpreter.hpp"
#include "string"
#include "iostream"
#include "evaluator.hpp"
#include "parser.hpp"

namespace Interpreter {

  namespace Colors {
    std::string green(const std::string &str) {
      return "\e[32m" + str + "\e[0m";
    }

    std::string red(const std::string &str) {
      return "\e[31m" + str + "\e[0m";
    }

    std::string cyan(const std::string &str) {
      return "\e[36m" + str + "\e[0m";
    }

    std::string blue(const std::string &str) {
      return "\e[34m" + str + "\e[0m";
    }

    std::string light_green(const std::string &str) {
      return "\e[1;32m" + str + "\e[0m";
    }
  }

  namespace {
    // Prints greeting message and info about
    // evaluator
    void info() {
      std::cout << Colors::red("\n  -- Algebraic expresion evaluator --\n\n");
      std::cout << Colors::blue(" ---------------------------------------\n");
      std::cout << Colors::blue("|") << " Supported operations: " << Colors::light_green("+, -, /, *, ()") << Colors::blue("  |\n");
      std::cout << Colors::blue("|") << " Enter " << Colors::light_green("'exit'") << " for exit" << Colors::blue("\t\t\t|\n");
      std::cout << Colors::blue(" ---------------------------------------\n\n");
    }

    // Reads from standard input
    std::string read() {
      std::cout << Colors::light_green(">>> ");

      std::string ret;
      std::getline(std::cin, ret);

      return ret;
    }

    // Evaluates given expression
    double evaluate(std::string &expression) {
      if (expression == "exit")
        exit(0);

      std::vector<std::string> tokens = ::Parser::parse(expression);

      return ::Evaluator::evaluate(tokens);
    }

    // Prints content to standard output
    template <class Object> void print(const Object &content) {
      std::cout << Colors::light_green(">>> ") << content << std::endl;
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
