#include "balance.hpp"
#include "iostream"

using namespace std;

string mark_unbalanced(const string &symbols, size_t idx) {
  string ret;

  for (size_t i = 0; i < symbols.size(); ++i)
    if (i == idx)
      ret.append("\e[31m" + string(1, symbols[i]) + "\e[0m");
    else
      ret.push_back(symbols[i]);

  return ret;
}

int main(int argc, char **argv) {
  if (argc == 2) {
    string symbols(argv[1]);

    Result result = balance(symbols);

    if (result.balanced)
      cout << "\n-- \e[32mBalanced\e[0m --\n\n";
    else
      cout << "\n-- \e[31mUnbalanced:\e[0m " << mark_unbalanced(symbols, result.index)  << " --\n\n";

  } else {
    cerr << "Invalid number of arguments: i.e. ./balance \"{()}\"" << endl;
    return - 1;
  }

  return 0;
}
