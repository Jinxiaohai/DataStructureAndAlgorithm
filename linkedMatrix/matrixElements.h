#ifndef MATRIXELEMENTS_H
#define MATRIXELEMENTS_H

#include "extendedChain.h"

template <class T>
struct rowElement {
  bool operator!=(const rowElement<T> &theRowElement) {
    return (value != theRowElement.value);
  }
  void output(std::ostream &out) const {
    out << "column " << col << "value " << value << std::endl;
  }

  int col;
  T value;
};

template <class T>
std::ostream &operator<<(std::ostream &out, const rowElement<T> &x) {
  x.output(out);
  return out;
}

template <class T>
struct headerElement {
  bool operator!=(const headerElement<T> &y) { return (row != y.row); }
  void output(std::ostream &out) const {
    out << "row " << row << std::endl << "  " << rowChain << std::endl;
  }

  int row;
  /// a chain to save the list data.
  extendedChain<rowElement<T>> rowChain;
};

template <class T>
std::ostream &operator<<(std::ostream &out, const headerElement<T> &x) {
  x.output(out);
  return out;
}

#endif  // MATRIXELEMENTS_H
