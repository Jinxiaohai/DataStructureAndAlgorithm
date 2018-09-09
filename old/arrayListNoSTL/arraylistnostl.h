#ifndef ARRAYLISTNOSTL_H
#define ARRAYLISTNOSTL_H

#include <iostream>
#include <sstream>
#include <string>

#include "changelength1d.h"
#include "linearlist.h"
#include "myExceptions.h"

template <class T>
class arrayListNoSTL : public linearList<T> {
 public:
  arrayListNoSTL(int initialCapacity = 10);
  arrayListNoSTL(const arrayListNoSTL<T>& theList);
  ~arrayListNoSTL() { delete[] element; }

  /// ADT methods
  bool empty() const { return listSize == 0; }
  int size() const { return listSize; }
  T& get(int theIndex) const;
  int indexOf(const T& theElement) const;
  void erase(int theIndex);
  void insert(int theIndex, const T& theElement);
  void output(std::ostream& out) const;

  int capacity() const { return arrayLength; }

 protected:
  void checkIndex(int theIndex) const;
  T* element;
  int arrayLength;
  int listSize;
};

template <class T>
arrayListNoSTL<T>::arrayListNoSTL(int initialCapacity) {
  if (initialCapacity < 1) {
    std::ostringstream s;
    s << "Initial capaicty = " << initialCapacity << " Must be > 0";
    throw illegalParameterValue(s.str());
  }

  arrayLength = initialCapacity;
  element = new T[arrayLength];
  listSize = 0;
}

template <class T>
arrayListNoSTL<T>::arrayListNoSTL(const arrayListNoSTL<T>& theList) {
  /// 复制变量
  arrayLength = theList.arrayLength;
  listSize = theList.listSize;
  element = new T[arrayLength];

  /// 真正的每个元素的复制
  for (int i = 0; i != listSize; ++i) {
    element[i] = theList.element[i];
  }
}

template <class T>
T& arrayListNoSTL<T>::get(int theIndex) const {
  checkIndex(theIndex);
  return element[theIndex];
}

template <class T>
int arrayListNoSTL<T>::indexOf(const T& theElement) const {
  for (int i = 0; i != listSize; ++i) {
    if (element[i] == theElement) {
      return i;
    }
  }
  return -1;
}

template <class T>
void arrayListNoSTL<T>::erase(int theIndex) {
  checkIndex(theIndex);

  for (int i = theIndex + 1; i != listSize; ++i) {
    element[i - 1] = element[i];
  }
  listSize = listSize - 1;
  element[listSize].~T();
}

template <class T>
void arrayListNoSTL<T>::insert(int theIndex, const T& theElement) {
  if (theIndex < 0 || theIndex > listSize) {
    std::ostringstream s;
    s << "index = " << theIndex << " size = " << listSize;
    throw illegalIndex(s.str());
  }

  if (listSize == arrayLength) {
    changeLength1D(element, arrayLength, 2 * arrayLength);
    arrayLength = 2 * arrayLength;
  }

  for (int i = listSize - 1; i >= theIndex; --i) {
    element[i + 1] = element[i];
  }

  element[theIndex] = theElement;
  listSize = listSize + 1;
}

template <class T>
void arrayListNoSTL<T>::output(ostream& out) const {
  for (int i = 0; i != listSize; ++i) {
    out << element[i] << "   ";
  }
}

template <class T>
void arrayListNoSTL<T>::checkIndex(int theIndex) const {
  if (theIndex < 0 || theIndex >= listSize) {
    std::ostringstream s;
    s << "index = " << theIndex << " size = " << listSize;
    throw illegalIndex(s.str());
  }
}

template <class T>
std::ostream& operator<<(std::ostream& out, const arrayListNoSTL<T>& x) {
  x.output(out);
  return out;
}

#endif  // ARRAYLISTNOSTL_H
