/**
 ** This file is part of the diagonalMatrix project.
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

#ifndef DIAGONALMATRIX_H
#define DIAGONALMATRIX_H

#include "myExceptions.h"

using namespace std;

template <class T>
class diagonalMatrix {
 public:
  diagonalMatrix(int theN = 10);
  ~diagonalMatrix() { delete[] element; }
  T get(int i, int j) const;
  void set(int i, int j, const T& theValue);

 private:
  int n;
  T* element;
};

template <class T>
diagonalMatrix<T>::diagonalMatrix(int theN) {
  if (theN < 1) {
    throw illegalParameterValue("Matrix size must be > 0");
  }
  n = theN;
  element = new T[n];
}

template <class T>
T diagonalMatrix<T>::get(int i, int j) const {
  if (i < 1 || j < 1 || i > n || j > n) {
    throw matrixIndexOutOfBounds();
  }

  if (i == j) {
    /// diagonal element
    return element[i - 1];
  } else {
    /// nondiagonal element
    return 0;
  }
}

template <class T>
void diagonalMatrix<T>::set(int i, int j, const T& theValue) {
  if (i < 1 || j < 1 || i > n || j > n) {
    throw matrixIndexOutOfBounds();
  }
  if (i == j) {
    element[i - 1] = theValue;
  } else {
    if (theValue != 0) {
      throw illegalParameterValue("nondiagonal elements must be zero");
    }
  }
}

#endif  // DIAGONALMATRIX_H
