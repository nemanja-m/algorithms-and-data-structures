#include "matrix.hpp"
#include "iostream"

using namespace std;

matrix<int> make_matrix() { return matrix<int>(10, 10); }

int main(int argc, char const *argv[]) {

  matrix<int> m(5, 5);
  m.print();

  cout << "\n\n";

  for (size_t i = 0; i < m.rows(); i++) {
    m[i][i] = 43;
    m[i][m.rows() - 1 - i] = 23;
  }

  m.print();
  cout << "\n\n";

  matrix<int> mm(m), mmm(make_matrix());

  mm.print();

  cout << "\n\n";
  mmm.print();

  return 0;
}
