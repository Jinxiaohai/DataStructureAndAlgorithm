#include <iostream>
#include <iterator>
#include <sstream>

#include "arraylist.h"
#include "changelength1d.h"

template <class T>
arrayList<T>::arrayList() {
  arrayLength = 0;
  listSize = 0;
  element = nullptr;
}

template <class T>
arrayList<T>::arrayList(const int initialCapacity) {
  if (initialCapacity < 1) {
    std::ostringstream s;
    s << "Inital capacity = " << initialCapacity << " must be > 0";
  }
  arrayLength = initialCapacity;
  element = new T[arrayLength];
  listSize = 0;
}

template <class T>
arrayList<T>::~arrayList() {
  delete[] element;
}

template <class T>
int arrayList<T>::lenght() const {
  return arrayLength;
}

template <class T>
int arrayList<T>::size() const {
  return listSize;
}

template <class T>
bool arrayList<T>::empty() const {
  return listSize == 0;
}

template <class T>
T &arrayList<T>::get(int theIndex) const {
  checkIndex(theIndex);
  return element[theIndex];
}

template <class T>
int arrayList<T>::indexOf(const T &theElement) const {
  int theIndex =
      static_cast<int>(find(element, element + listSize, theElement) - element);
  if (theIndex == listSize) {
    return -1;
  } else {
    return theIndex;
  }
}

template <class T>
void arrayList<T>::erase(int theIndex) {
  checkIndex(theIndex);
  copy(element + theIndex + 1, element + listSize, element + theIndex);
  element[--listSize].~T();
}

template <class T>
void arrayList<T>::insert(int theIndex, const T &theElement) {
  if (theIndex < 0 || theIndex > listSize) {
    std::ostringstream s;
    s << "index = " << theIndex << " size = " << listSize;
  }
  if (listSize == arrayLength) {
    changeLength1D(element, arrayLength, 2 * arrayLength);
    arrayLength *= 2;
  }
  copy_backward(element + theIndex, element + listSize, element + theIndex + 1);
  element[theIndex] = theElement;
  ++listSize;
}

template <class T>
void arrayList<T>::output(std::ostream &out) const {
  copy(element, element + listSize, std::ostream_iterator<T>(out, "  "));
}

template <class T>
void arrayList<T>::checkIndex(int theIndex) const {
  if (theIndex < 0 || theIndex >= listSize) {
    std::ostringstream s;
    s << "index = " << theIndex << " size = " << listSize;
  }
}

template <class T>
std::ostream &operator<<(std::ostream &out, const arrayList<T> &theList) {
  theList.output(out);
  return out;
}
