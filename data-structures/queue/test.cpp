#include "queue.hpp"
#include "iostream"

using namespace std;

int main(int argc, char** argv) {
  Queue<int> queue;

  cout << "\n-- Enqueuing --" << endl;

  for (int i = 0; i < 17; i++) {
    cout << "--> " << i << endl;
    queue.enqueue(i);
  }

  cout << "\nSize: " << queue.size() << endl;
  cout << "Capacity: " << queue.capacity() << endl;

  cout << "\n-- Dequeuing --" << endl;
  while (!queue.empty())
    cout << queue.dequeue() << " ";

  cout << "\n\n--> 43\n--> 23" << endl;
  queue.enqueue(43);
  queue.enqueue(23);

  cout << "\n-- Clear queue --" << endl;
  queue.clear();

  cout << "Size: " << queue.size() << endl;

  return 0;
}
