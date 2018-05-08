#include <iostream>

#include "functionhead.h"

int main(int argc, char *argv[]) {
  std::cout << "Moves for a three disk problem are" << std::endl;
  towersOfHanoi(10, 1, 2, 3);

  std::cout << "The total step is " << totalStep << std::endl;
  return 0;
}
