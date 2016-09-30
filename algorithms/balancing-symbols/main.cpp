#include "balance.hpp"
#include "iostream"

using namespace std;

int main(int argc, char **argv) {
  if (argc == 2) {
    string symbols(argv[1]);

    Result result = balance(symbols);

    if (result.balanced)
      cout << "Balanced" << endl;
    else
      cout << "Unbalanced: " << result.index << endl;

  } else {
    cerr << "Invalid number of arguments: i.e. ./balance \"{()}\"" << endl;
    return - 1;
  }

  return 0;
}
