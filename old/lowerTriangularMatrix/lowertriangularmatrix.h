/**
 ** This file is part of the lowerTriangularMatrix project.
 ** Copyright 2018 xiaohai <xiaohaijin@outlook.com>.
 **
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/

#ifndef LOWERTRIANGULARMATRIX_H
#define LOWERTRIANGULARMATRIX_H
/// x 0 0 0 0 0 0 0
/// x x 0 0 0 0 0 0
/// x x x 0 0 0 0 0
/// x x x x 0 0 0 0
/// x x x x x 0 0 0
/// x x x x x x 0 0
/// x x x x x x x 0
/// x x x x x x x x
/// element = i(i-1)+(j-1)

#include "myExceptions.h"
using namespace std;

template <class T>
class lowerTriangularMatrix {
 public:
  lowerTriangularMatrix(int theN = 10);
  ~lowerTriangularMatrix() { delete[] element; }
  T get(int i, int j) const;
  void set(int i, int j, const T &theValue);

 private:
  int n;
  T *element;
};
#endif  // LOWERTRIANGULARMATRIX_H

template <class T>
lowerTriangularMatrix<T>::lowerTriangularMatrix(int theN) {
  if (theN < 1) {
    throw illegalParameterValue("Matrix size must be > 0");
  }

  n = theN;
  element = new T[n * (n - 1) / 2];
}

template <class T>
T lowerTriangularMatrix<T>::get(int i, int j) const {
  if (i < 1 || j < 1 || i > n || j > n) {
    throw matrixIndexOutOfBounds();
  }

  if (i >= j) {
    return element[i * (i - 1) / 2 + (j - 1)];
  } else {
    return 0;
  }
}

template <class T>
void lowerTriangularMatrix<T>::set(int i, int j, const T &theValue) {
  if (i < 1 || j < 1 || i > n || j > n) {
    throw matrixIndexOutOfBounds();
  }

  if (i >= j) {
    element[i * (i - 1) / 2 + (j - 1)] = theValue;
  } else {
    if (theValue != 0) {
      throw illegalParameterValue(
          "elements not in lower triangle must be zero");
    }
  }
}
