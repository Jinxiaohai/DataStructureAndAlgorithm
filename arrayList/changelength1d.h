#ifndef CHANGELENGTH1D_H
#define CHANGELENGTH1D_H

#include <myExceptions.h>

template <class T>
void changeLength1D(T*& a, int oldLength, int newLength) {
  if (newLength < 0) {
    throw illegalParameterValue("new Length must be > 0");
  }

  T* temp = new T[newLength];
  int number = std::min(oldLength, newLength);
  std::copy(a, a + number, temp);
  delete[] a;
  a = temp;
}

#endif  // CHANGELENGTH1D_H
