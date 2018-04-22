/**
 ** This file is part of the matrix project.
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

#ifndef MATRIX_H
#define MATRIX_H

#include "myExceptions.h"

using namespace std;

template <class T>
class matrix {
  template <class U>
  friend ostream& operator<<(ostream& out, const matrix<U>& theMatrix);

 public:
  matrix(int theRows = 0, int theColumns = 0);
  matrix(const matrix<T>& theMatrix);
  ~matrix() { delete[] element; }

  int rows() const { return theRows; }
  int columnss() const { return theColumns; }
  T& operator()(int i, int j) const;
  matrix<T>& operator=(const matrix<T>& theMatrix);
  /// positive
  matrix<T> operator+() const;
  matrix<T> operator+(const matrix<T>& theMatrix) const;
  /// minus
  matrix<T> operator-() const;
  matrix<T> operator-(const matrix<T>& theMatrix) const;
  /// multiply
  matrix<T> operator*(const matrix<T>& theMatrix) const;

  /// this not supplied in math
  matrix<T>& operator+=(const T& theValue);

 private:
  int theRows;
  int theColumns;
  T* element;
};

template <class T>
matrix<T>::matrix(int theRows, int theColumns) {
  if (theRows < 0 || theColumns < 0) {
    throw illegalParameterValue("Rows and columns must be > 0");
  }
  /// the condition is theRows = 0 and theColumns = 0,
  /// or theRows != 0 and theColumns != 0.
  if ((theRows == 0 || theColumns == 0) && (theRows != 0 || theColumns != 0)) {
    throw illegalParameterValue(
        "Either both or neither rows and columns should be zero");
  }
  this->theRows = theRows;
  this->theColumns = theColumns;
  element = new T[this->theRows * this->theColumns];
}

template <class T>
matrix<T>::matrix(const matrix<T>& theMatrix) {
  theRows = theMatrix.theRows;
  theColumns = theMatrix.theColumns;
  element = new T[theRows * theColumns];

  /// copy each element of m
  copy(theMatrix.element, theMatrix.element + theRows * theColumns, element);
}

template <class T>
T& matrix<T>::operator()(int i, int j) const {
  if (i < 1 || i > theRows || j < 1 || j > theColumns) {
    throw matrixIndexOutOfBounds();
  }

  /// the row
  return element[(i - 1) * theColumns + (j - 1)];
}

template <class T>
matrix<T>& matrix<T>::operator=(const matrix<T>& theMatrix) {
  if (this != &theMatrix) {
    delete[] element;
    theRows = theMatrix.theRows;
    theColumns = theMatrix.theColumns;
    element = new T[theRows * theColumns];
    copy(theMatrix.element, theMatrix.element + theRows * theColumns, element);
  }
  return *this;
}

template <class T>
matrix<T> matrix<T>::operator+() const {
  return *this;
}

/// \brief return w = (*this) + theMatrix;
template <class T>
matrix<T> matrix<T>::operator+(const matrix<T>& theMatrix) const {
  if (theRows != theMatrix.theRows || theColumns != theMatrix.theColumns) {
    throw matrixSizeMismatch();
  }

  matrix<T> temp(theRows, theColumns);
  for (int i = 0; i != theRows * theColumns; ++i) {
    temp.element[i] = element[i] + theMatrix.element[i];
  }

  return temp;
}

/// \brief return w = -(*this).
template <class T>
matrix<T> matrix<T>::operator-() const {
  matrix<T> temp(theRows, theColumns);
  for (int i = 0; i != theRows * theColumns; ++i) {
    temp.element[i] = -element[i];
  }

  return temp;
}

/// \brief (*this) - m
template <class T>
matrix<T> matrix<T>::operator-(const matrix<T>& theMatrix) const {
  if (theRows != theMatrix.theRows || theColumns != theMatrix.theColumns) {
    throw matrixSizeMismatch();
  }

  matrix<T> temp(theRows, theColumns);
  for (int i = 0; i != theRows * theColumns; ++i) {
    temp.element[i] = element[i] - theMatrix.element[i];
  }

  return temp;
}

/// \brief matrix multiply.
/// C_{ij} = \sum_{k = 0}^{theColumns}A_{ik}B_{kj}
/// \return m = (*this)*m
template <class T>
matrix<T> matrix<T>::operator*(const matrix<T>& theMatrix) const {
  if (theColumns != theMatrix.theRows) {
    throw matrixSizeMismatch();
  }

  matrix<T> temp(theRows, theMatrix.theColumns);

  int ct = 0, cm = 0, cw = 0;

  for (int i = 1; i <= theRows; ++i) {
    for (int j = 1; j <= theMatrix.theColumns; ++j) {
      /// compute first term of temp(i, j)
      T sum = element[ct] * theMatrix.element[cm];
      for (int k = 2; k <= theColumns; ++k) {
        /// next term in row i of *this
        ++ct;
        /// next in column j of theMatrix
        cm += theMatrix.theColumns;

        sum += element[ct] * theMatrix.element[cm];
      }
      temp.element[cw++] = sum;

      /// reset to start of next row and first column
      ct = ct - (theColumns - 1);
      cm = j;
    }
    ct += theColumns - 1;
    cm = 0;
  }

  return temp;
}

/// \brief error
template <class T>
matrix<T>& matrix<T>::operator+=(const T& theValue) {
  for (int i = 0; i != theRows * theColumns; ++i) {
    element[i] += theValue;
  }
  return *this;
}

template <class T>
ostream& operator<<(ostream& out, const matrix<T>& theMatrix) {
  int k = 0;
  for (int i = 0; i != theMatrix.theRows; ++i) {
    for (int j = 0; j != theMatrix.theColumns; ++j) {
      out << theMatrix.element[k++] << "   ";
    }
    out << endl;
  }
  return out;
}

#endif  // MATRIX_H
