#ifndef LINKEDMATRIX_H
#define LINKEDMATRIX_H

#include <iostream>

#include "extendedChain.h"
#include "matrixElements.h"

template <class T>
class linkedMatrix {
  friend std::ostream& operator<<(std::ostream&, linkedMatrix<T>&);
  friend std::istream& operator>>(std::istream&, linkedMatrix<T>&);

 public:
  linkedMatrix() {}
  ~linkedMatrix() {}
  void transpose(linkedMatrix<T>& b);

 private:
  /// number of rows in matrix
  int rows;
  /// number of columns in matrix
  int cols;
  extendedChain<headerElement<T>> headerChain;
};

#endif  // LINKEDMATRIX_H

template <class T>
ostream& operator<<(ostream& out, linkedMatrix<T>& x) {
  /// Put matrix x into the output stream out
  out << "rows = " << x.rows << " columns = " << x.cols << std::endl;
  if (x.headerChain.empty()) {
    out << "No non-zero terms" << std::endl;
    return out;
  }

  out << x.headerChain << endl;
  return out;
}

template <class T>
istream& operator>>(istream& in, linkedMatrix<T>& x) {
  /// delete all nodes from x
  x.headerChain.clear();

  int terms;
  std::cout << "Enter number of rows, columns, and terms" << std::endl;
  in >> x.rows >> x.cols >> terms;

  headerElement<T> header;
  header.row = 0;

  for (int i = 1; i <= terms; ++i) {
    std::cout << "Enter row, column, and value of term " << i << std::endl;
    rowElement<T>* term = new rowElement<T>;
    int row;
    in >> row >> term->col >> term->value;

    if (row > header.row) {
      if (header.row != 0) {
        x.headerChain.push_back(header);
      }

      header.row = row;
      header.rowChain.zero();
    }
    header.rowChain.push_back(*term);
  }

  if (header.row != 0) {
    x.headerChain.push_back(header);
  }
  header.rowChain.zero();

  return in;
}

template <class T>
void linkedMatrix<T>::transpose(linkedMatrix<T>& b) {
  b.headerChain.clear();

  extendedChain<rowElement<T>>* bin;
  bin = new extendedChain<rowElement<T>>[cols + 1];

  extendedChain<headerElement<T>>::iterator ih = headerChain.begin();
  extendedChain<headerElement<T>>::iterator ihEnd = headerChain.end();

  while (ih != ihEnd) {
    int r = ih->row;
    ir = ih->rowChain.begin();
    irEnd = ih->rowChain.end();

    rowElement<T> x;
    x.col = r;

    while (ir != irEnd) {
      x.value = ir->value;
      bin[ir->col].push_back(x);
      ++ir;
    }
    ++ih;
  }
  b.rows = cols;
  b.cols = rows;

  headerElement<T> h;
  for (int i = 1; i <= cols; ++i) {
    if (!bin[i].empty()) {
      h.row = i;
      h.rowChain = bin[i];
      b.headerChain.push_back(h);
      bin[i].zero();
    }
  }
  h.rowChain.zero();
  delete[] bin;
}
