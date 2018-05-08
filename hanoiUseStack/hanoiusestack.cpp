#include <iostream>

#include "arraystack.h"

using namespace std;

/// global variable, tower[1:3] are the three towers
arrayStack<int> tower[4];

void moveAndShow(int n, int x, int y, int z) {
  if (n > 0) {
    moveAndShow(n - 1, x, z, y);
    int d = tower[x].top();
    tower[x].pop();
    tower[y].push(d);
    cout << "Move disk " << d << " from tower " << x << " to top of tower " << y
         << endl;
    moveAndShow(n - 1, z, y, x);
  }
}

void towersOfHanoi(int n) {
  for (int d = n; d > 0; --d) {
    tower[1].push(d);
  }
  moveAndShow(n, 1, 2, 3);
}

int main(int argc, char* argv[]) {
  cout << "Moves for a three disk problem are " << endl;
  towersOfHanoi(3);
  return 0;
}
