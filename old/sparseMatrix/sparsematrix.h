#ifndef sparseMatrix_H
#define sparseMatrix_H

#include <iostream>

#include "extendedarraylist.h"
#include "matrixterm.h"
#include "myExceptions.h"

template <class T>
class sparseMatrix {
  friend std::ostream& operator<<(std::ostream& out,
                                  sparseMatrix<T>& thesparseMatrix);
  friend std::istream& operator>>(std::istream& in,
                                  sparseMatrix<T>& thesparseMatrix);

 public:
  void transpose(sparseMatrix<T>& thesparseMatrix);
  void add(sparseMatrix<T>& leftHand, sparseMatrix<T>& rightHand);

 private:
  int rows;
  int cols;
  arrayList<matrixTerm<T>> terms;
};

template <class T>
ostream& operator<<(ostream& out, sparseMatrix<T>& thesparseMatrix) {
  out << "rows = " << thesparseMatrix.rows
      << " columns = " << thesparseMatrix.cols << endl;

  out << "nonzero terms = " << thesparseMatrix.terms.size() << endl;

  for (arrayList<matrixTerm<T>>::iterator i = thesparseMatrix.terms.begin();
       i != thesparseMatrix.terms.end(); ++i) {
    out << "a(" << (*i).row << ',' << (*i).col << ") = " << (*i).value << endl;
  }
  return out;
}

template <class T>
istream& operator>>(std::istream& in, sparseMatrix<T>& thesparseMatrix) {
  int numberOfTerms;
  cout << "Enter number of rows, columns, and #terms" << endl;

  in >> thesparseMatrix.rows >> thesparseMatrix.cols >> numberOfTerms;
  thesparseMatrix.terms.reSet(numberOfTerms);

  thesparseMatrix.reSet(numberOfTerms);

  matrixTerm<T> mTerm;
  for (int i = 0; i != numberOfTerms; ++i) {
    cout << "Enter row, column, and value of term " << (i + 1) << endl;
    in >> mTerm.row >> mTerm.col >> mTerm.value;
    thesparseMatrix.terms.set(i, mTerm);
  }

  return in;
}

template <class T>
void sparseMatrix<T>::transpose(sparseMatrix<T>& thesparseMatrix) {
  thesparseMatrix.cols = rows;
  thesparseMatrix.rows = cols;
  thesparseMatrix.terms.reSet(terms.size());

  /// initialize to compute transpose
  int* colSize = new int[cols + 1];
  int* rowNext = new int[cols + 1];

  for (int i = 0; i != cols; ++i) {
    colSize[i] = 0;
  }
  for (arrayList<matrixTerm<T>>::iterator i = terms.begin(); i != terms.end();
       ++i) {
    colSize[(*i).col]++;
  }

  rowNext[1] = 0;
  for (int i = 2; i <= cols; ++i) {
    rowNext[i] = rowNext[i - 1] + colSize[i - 1];
  }

  matrixTerm<T> mTerm;
  for (arrayList<matrixTerm<T>>::iterator i = terms.begin(); i != terms.end();
       ++i) {
    int j = rowNext[(*i).col]++;
    mTerm.row = (*i).col;
    mTerm.col = (*i).row;
    mTerm.value = (*i).value;
    thesparseMatrix.terms.set(j, mTerm);
  }
}

template <class T>
void sparseMatrix<T>::add(sparseMatrix<T>& b,
                          sparseMatrix<T>& c) {  // Compute c = (*this) + b.

  // verify compatibility
  if (rows != b.rows || cols != b.cols)
    throw matrixSizeMismatch();  // incompatible matrices

  // set characteristics of result c
  c.rows = rows;
  c.cols = cols;
  c.terms.clear();
  int cSize = 0;

  // define iterators for *this and b
  arrayList<matrixTerm<T>>::iterator it = terms.begin();
  arrayList<matrixTerm<T>>::iterator ib = b.terms.begin();
  arrayList<matrixTerm<T>>::iterator itEnd = terms.end();
  arrayList<matrixTerm<T>>::iterator ibEnd = b.terms.end();

  // move through *this and b adding like terms
  while (it != itEnd && ib != ibEnd) {
    // row-major index plus cols of each term
    int tIndex = (*it).row * cols + (*it).col;
    int bIndex = (*ib).row * cols + (*ib).col;

    if (tIndex < bIndex) {  // b term comes later
      c.terms.insert(cSize++, *it);
      it++;
    } else {
      if (tIndex == bIndex) {  // both in same position

        // append to c only if sum not zero
        if ((*it).value + (*ib).value != 0) {
          matrixTerm<T> mTerm;
          mTerm.row = (*it).row;
          mTerm.col = (*it).col;
          mTerm.value = (*it).value + (*ib).value;
          c.terms.insert(cSize++, mTerm);
        }

        it++;
        ib++;
      } else {  // a term comes later
        c.terms.insert(cSize++, *ib);
        ib++;
      }
    }
  }

  // copy over remaining terms
  for (; it != itEnd; it++) c.terms.insert(cSize++, *it);
  for (; ib != ibEnd; ib++) c.terms.insert(cSize++, *ib);
}

#endif  // sparseMatrix_H
