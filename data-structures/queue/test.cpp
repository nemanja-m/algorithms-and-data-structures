#include "queue.hpp"
#include "iostream"

using namespace std;

int main(int argc, char** argv) {
  Queue<int> queue;

  cout << "\n-- Enqueuing --" << endl;

  for (int i = 0; i < 18; i++) {
    cout << "--> " << i << endl;
    queue.enqueue(i);
  }

  cout << "\nCapacity: " << queue.capacity() << endl;

  cout << "\n-- Dequeuing --" << endl;

  while (!queue.empty())
    cout << queue.dequeue() << " ";

  cout << endl;

  return 0;
}
