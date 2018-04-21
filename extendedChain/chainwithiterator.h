/**
 ** This file is part of the chainWithIterator project.
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

#ifndef CHAINWITHITERATOR_H
#define CHAINWITHITERATOR_H

#include <iostream>
#include <sstream>
#include <string>
#include "chainnode.h"
#include "linearlist.h"
#include "myExceptions.h"

using namespace std;

class linkedDigraph;
template <class T>
class linkedWDigraph;

template <class T>
class chain : public linearList<T> {
  friend linkedDigraph;
  friend linkedWDigraph<int>;
  friend linkedWDigraph<float>;
  friend linkedWDigraph<double>;

 public:
  chain(int initialCapacity = 10);
  chain(const chain<T>& theChain);
  ~chain();

  bool empty() const { return listSize == 0; }
  int size() const { return listSize; }
  T& get(int theIndex) const;
  int indexOf(const T& theElement) const;
  void erase(int theIndex);
  void insert(int theIndex, const T& theElement);
  void output(ostream& out) const;

  class iterator;
  iterator begin() { return iterator(firstNode); }
  iterator end() { return iterator(nullptr); }

  class iterator {
   public:
    typedef forward_iterator_tag iterator_category;
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef T* pointer;
    typedef T& reference;

    ///
    /// \brief iterator constructor
    /// \param theNode
    ///
    iterator(chainNode<T>* theNode = nullptr) { node = theNode; }

    /// \brief dereferencing operators
    T& operator*() const { return node->element; }
    T* operator->() const { return &(node->element); }

    /// \brief only forward,
    iterator& operator++() {
      node = node->next;
      return *this;
    }
    iterator operator++(int) {
      iterator old = *this;
      node = node->next;
      return old;
    }

    bool operator!=(const iterator right) const { return node != right.node; }
    bool operator==(const iterator right) const { return !(operator!=(right)); }

   protected:
    chainNode<T>* node;
  };

 protected:
  void checkIndex(int theIndex) const;
  chainNode<T>* firstNode;
  int listSize;
};

template <class T>
chain<T>::chain(int initialCapacity) {
  if (initialCapacity < 1) {
    ostringstream s;
    s << "Initial capacity = " << initialCapacity << " Must be > 0";
    throw illegalParameterValue(s.str());
  }

  firstNode = nullptr;
  listSize = 0;
}

template <class T>
chain<T>::chain(const chain<T>& theChain) {
  listSize = theChain.listSize;

  if (listSize == 0) {
    firstNode = nullptr;
    return;
  }

  chainNode<T>* sourceNode = theChain.firstNode;
  firstNode = new chainNode<T>(sourceNode->element);

  /// \brief sourceNode - targetNode is 1
  sourceNode = sourceNode->next;
  chainNode<T>* targetNode = firstNode;

  while (sourceNode != nullptr) {
    targetNode->next = chainNode<T>(sourceNode->element);
    targetNode = targetNode->next;
    sourceNode = sourceNode->next;
  }

  targetNode->next = nullptr;
}

template <class T>
chain<T>::~chain() {
  chainNode<T>* nextNode;
  while (firstNode != nullptr) {
    nextNode = firstNode->next;
    delete firstNode;
    firstNode = nextNode;
  }
}

template <class T>
T& chain<T>::get(int theIndex) const {
  checkIndex(theIndex);

  chainNode<T>* currentNode = firstNode;
  for (int i = 0; i != theIndex; ++i) {
    currentNode = currentNode->next;
  }
  return currentNode->element;
}

template <class T>
int chain<T>::indexOf(const T& theElement) const {
  chainNode<T>* currentNode = firstNode;
  int index = 0;

  while (currentNode != nullptr && currentNode->element != theElement) {
    currentNode = currentNode->next;
    ++index;
  }

  if (currentNode == nullptr) {
    return -1;
  } else {
    return index;
  }
}

template <class T>
void chain<T>::erase(int theIndex) {
  checkIndex(theIndex);

  chainNode<T>* deleteNode;
  if (theIndex == 0) {
    deleteNode = firstNode;
    firstNode = firstNode->next;
  } else {
    chainNode<T>* p = firstNode;
    for (int i = 0; i != theIndex - 1; ++i) {
      p = p->next;
    }
    deleteNode = p->next;
    p->next = p->next->next;
  }
  --listSize;
  delete deleteNode;
}

template <class T>
void chain<T>::insert(int theIndex, const T& theElement) {
  if (theIndex < 0 || theIndex > listSize) {
    ostringstream s;
    s << "index = " << theIndex << " size = " << listSize;
    throw illegalIndex(s.str());
  }

  if (theIndex == 0) {
    firstNode = new chainNode<T>(theElement, firstNode);
  } else {
    chainNode<T>* p = firstNode;
    for (int i = 0; i != theIndex - 1; ++i) {
      p = p->next;
    }
    p->next = new chainNode<T>(theElement, p->next);
  }

  ++listSize;
}

template <class T>
void chain<T>::output(ostream& out) const {
  for (chainNode<T>* currentNode = firstNode; currentNode != nullptr;
       currentNode = currentNode->next) {
    out << currentNode->element << "   ";
  }
}

template <class T>
void chain<T>::checkIndex(int theIndex) const {
  if (theIndex < 0 || theIndex >= listSize) {
    ostringstream s;
    s << "index = " << theIndex << " size = " << listSize;
    throw illegalIndex(s.str());
  }
}

template <class T>
ostream& operator<<(ostream& out, const chain<T>& x) {
  x.output(out);
  return out;
}

#endif  // CHAINWITHITERATOR_H
