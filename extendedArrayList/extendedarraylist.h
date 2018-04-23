/**
 ** This file is part of the extendArrayList project.
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

#ifndef EXTENDEDARRAYLIST_H
#define EXTENDEDARRAYLIST_H

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

  /// ADT methods
  bool empty() const { return listSize == 0; }
  int size() const { return listSize; }
  T& get(int theIndex) const;
  int indexOf(const T& theElement) const;
  void erase(int theIndex);
  void insert(int theIndex, const T& theElement);
  void output(std::ostream& out) const;
  int capacity() const { return arrayLength; }
  void reSet(int);
  void set(int theIndex, const T& theElement);
  void clear() { listSize = 0; }

  /// iterators to start and end of list
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

    /// constructor
    iterator(T* thePosition = 0) { position = thePosition; }

    // dereferencing operators
    T& operator*() const { return *position; }
    T* operator->() const { return &(this->operator*()); }

    /// \brief return *this after ++position.
    iterator& operator++() {
      ++position;
      return *this;
    }
    /// \brief return old value before ++position.
    iterator operator++(int) {
      iterator old = *this;
      ++position;
      return old;
    }

    iterator& operator--() {
      --position;
      return *this;
    }
    iterator operator--(int) {
      iterator old = *this;
      --position;
      return old;
    }

    bool operator!=(const iterator right) const {
      return position != right.position;
    }
    bool operator==(const iterator right) const { return !operator!=(right); }

   protected:
    T* position;
  };

 protected:
  void checkIndex(int theIndex) const;
  T* element;
  int arrayLength;
  int listSize;
};

///
/// \brief arrayList<T>::arrayList constructor.
/// \param initialCapacity capatity
template <class T>
arrayList<T>::arrayList(int initialCapacity) {
  if (initialCapacity < 1) {
    std::ostringstream s;
    s << "Initial capacity = " << initialCapacity << " must be > 0";
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
  int theIndex = static_cast<int>(
      std::find(element, element + listSize, theElement) - element);

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

  --listSize;
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
void arrayList<T>::reSet(int theSize) {
  if (theSize < 0) {
    std::ostringstream s;
    s << "Requested size = " << theSize << " must be >= 0";
    throw illegalParameterValue(s.str());
  }

  if (theSize > arrayLength) {
    delete element;
    element = new T[theSize];
    arrayLength = listSize;
  }
  listSize = theSize;
}

template <class T>
void arrayList<T>::set(int theIndex, const T& theElement) {
  checkIndex(theIndex);
  element[theIndex] = theElement;
}

template <class T>
void arrayList<T>::checkIndex(int theIndex) const {
  if (theIndex < 0 || theIndex >= listSize) {
    std::ostringstream s;
    s << "Index = " << theIndex << " size = " << listSize;
    throw illegalIndex(s.str());
  }
}

#endif  // EXTENDEDARRAYLIST_H
