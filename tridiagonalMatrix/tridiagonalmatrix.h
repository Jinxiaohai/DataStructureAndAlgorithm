/**
 ** This file is part of the tridiagonalMatrix project.
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

#ifndef TRIDIAGONALMATRIX_H
#define TRIDIAGONALMATRIX_H

#include "myExceptions.h"

using namespace std;

/// x x 0 0 0 0 0
/// x x x 0 0 0 0
/// 0 x x x 0 0 0
/// 0 0 x x x 0 0
/// 0 0 0 x x x 0
/// 0 0 0 0 x x x
/// 0 0 0 0 0 x x

template <class T>
class tridiagonalMatrix {
 public:
  tridiagonalMatrix(int theN = 10);
  ~tridiagonalMatrix() { delete[] element; }
  T get(int i, int j) const;
  void set(int i, int j, const T& theValue);

 private:
  int n;
  T* element;
};

template <class T>
tridiagonalMatrix<T>::tridiagonalMatrix(int theN) {
  if (theN < 1) {
    throw illegalParameterValue("Matrix size must be > 0");
  }

  n = theN;
  element = new T[3 * n - 2];
}

template <class T>
T tridiagonalMatrix<T>::get(int i, int j) const {
  /// return (i, j)th element of matrix.
  if (i < 1 || j < 1 || i > n || j > n) {
    throw matrixIndexOutOfBounds();
  }

  switch (i - j) {
    case 1:
      return element[(i - 1) - 1];
    case 0:
      return element[(n - 1) + (i)-1];
    case -1:
      return element[(n - 1) + n + (i)-1];
    default:
      return 0;
  }
}

template <class T>
void tridiagonalMatrix<T>::set(int i, int j, const T& theValue) {
  if (i < 1 || j < 1 || i > n || j > n) {
    throw matrixIndexOutOfBounds();
  }

  switch (i - j) {
    case 1:
      element[(i - 1) - 1] = theValue;
      break;
    case 0:
      element[(n - 1) + (i)-1] = theValue;
      break;
    case -1:
      element[(n - 1) + n + (i)-1] = theValue;
      break;
    default:
      if (theValue != 0) {
        throw illegalParameterValue("non-tridiagonal elements must be zero.");
      }
  }
}

#endif  // TRIDIAGONALMATRIX_H
