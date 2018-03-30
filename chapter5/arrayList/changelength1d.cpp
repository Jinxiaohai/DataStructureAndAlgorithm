#include <algorithm>
#include <cmath>
#include <iostream>

#include "changelength1d.h"

template <class T>
void changeLength1D(T*& a, int oldLength, int newLength) {
  if (newLength < 0) {
    std::cout << "new length must be > 0" << std::endl;
  }
  T* temp = new T[newLength];
  int number = std::min(oldLength, newLength);
  copy(a, a + number, temp);
  delete a;
  a = temp;
}
