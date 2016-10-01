#include "convertor.hpp"
#include "iostream"
#include "algorithm"

using namespace std;

int main(int argc, char **argv) {
  if (argc == 1) {
    cerr << "Invalid number of arguments: ./evaluate 'expression'" << endl;
    return -1;
  }

  string args;

  for (int i = 1; i < argc; ++i) {
    args.append(argv[i]);
  }

  // Erase spaces
  args.erase(remove_if(args.begin(), args.end(), ::isspace), args.end());

  cout << "\nResult: " << "\e[32m" << evaluate(args) << "\e[0m\n\n";

  return 0;
}
