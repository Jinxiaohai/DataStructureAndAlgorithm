#include <iostream>

#include "functionhead.h"

long int totalStep = 0;

void towersOfHanoi(int n, int x, int y, int z) {
  if (n > 0) {
    towersOfHanoi(n - 1, x, z, y);
    std::cout << "Move top disk from tower " << x << " to top of tower" << y
              << std::endl;
    ++totalStep;
    towersOfHanoi(n - 1, z, y, x);
  }
}
