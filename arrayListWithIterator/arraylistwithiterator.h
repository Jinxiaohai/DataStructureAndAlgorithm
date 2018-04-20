#ifndef ARRAYLISTWITHITERATOR_H
#define ARRAYLISTWITHITERATOR_H

#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include "changelength1d.h"
#include "linearlist.h"
#include "myExceptions.h"

template <class T>
class arrayList : public linearList<T> {
 public:
  arrayList(int initialCapacity = 10);
  arrayList(const arrayList<T>& theList);
  ~arrayList() { delete[] element; }

  bool empty() const { return listSize == 0; }
  int size() const { return listSize; }
  T& get(int theIndex) const;
  int indexOf(const T& theElement) const;
  void erase(int theIndex);
  void insert(int theIndex, const T& theElement);
  void output(std::ostream& out) const;

  int capacity() const { return arrayLength; }

  /// 迭代器
  class iterator;
  iterator begin() { return iterator(element); }
  iterator end() { return iterator(element + listSize); }

  class iterator {
   public:
    typedef bidirectional_iterator_tag iterator_category;
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef T* pointer;
    typedef T& reference;

    iterator(T* thePosition = 0) { position = thePosition; }

    /// dereferencing operators
    T& operator*() const { return *position; }
    /// return the address of dereference operators
    T* operator->() const { return &(operator*()); }

    /// return dereference
    iterator& operator++() {
      ++position;
      return *this;
    }
    iterator operator++(int) {
      iterator old = *this;
      ++position;
      return old;
    }

    /// return dereference
    iterator& operator--() {
      --position;
      return *this;
    }
    iterator operator--(int) {
      iterator old = *this;
      --position;
      return old;
    }

    bool operator!=(const iterator rightHand) const {
      return position != rightHand.position;
    }
    bool operator==(const iterator rightHand) const {
      return !(position != rightHand.position);
    }

   protected:
    T* position;
  };

 protected:
  void checkIndex(int theIndex) const;
  T* element;
  int arrayLength;
  int listSize;
};

template <class T>
arrayList<T>::arrayList(int initialCapacity) {
  if (initialCapacity < 1) {
    std::ostringstream s;
    s << "Initial capacity = " << initialCapacity << " Must be > 0";
    throw illegalParameterValue(s.str());
  }

  arrayLength = initialCapacity;
  element = new T[arrayLength];
  listSize = 0;
}

template <class T>
arrayList<T>::arrayList(const arrayList<T>& theList) {
  arrayLength = theList.arrayLength;
  listSize = theList.listSize;
  element = new T[arrayLength];
  std::copy(theList.element, theList.element + listSize, element);
}

template <class T>
T& arrayList<T>::get(int theIndex) const {
  checkIndex(theIndex);
  return element[theIndex];
}

template <class T>
int arrayList<T>::indexOf(const T& theElement) const {
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
  std::copy(element + theIndex + 1, element + listSize, element + theIndex);
  listSize = listSize - 1;
  element[listSize].~T();
}

template <class T>
void arrayList<T>::insert(int theIndex, const T& theElement) {
  if (theIndex < 0 || theIndex > listSize) {
    std::ostringstream s;
    s << "index = " << theIndex << " size = " << listSize;
    throw illegalIndex(s.str());
  }

  if (listSize == arrayLength) {
    changeLength1D(element, arrayLength, 2 * arrayLength);
    arrayLength = 2 * arrayLength;
  }

  std::copy_backward(element + theIndex, element + listSize,
                     element + listSize + 1);
  element[theIndex] = theElement;
  ++listSize;
}

template <class T>
void arrayList<T>::output(ostream& out) const {
  std::copy(element, element + listSize, std::ostream_iterator<T>(out, "  "));
}

template <class T>
void arrayList<T>::checkIndex(int theIndex) const {
  if (theIndex < 0 || theIndex >= listSize) {
    std::ostringstream s;
    s << "index = " << theIndex << " size = " << listSize;
    throw illegalIndex(s.str());
  }
}

template <class T>
std::ostream& operator<<(std::ostream& out, const arrayList<T>& x) {
  x.output(out);
  return out;
}

#endif  // ARRAYLISTWITHITERATOR_H
