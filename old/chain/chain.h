#ifndef CHAIN_H
#define CHAIN_H

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
  void output(std::ostream& out) const;

 protected:
  void checkIndex(int theIndex) const;
  chainNode<T>* firstNode;
  int listSize;
};

template <class T>
chain<T>::chain(int initialCapacity) {
  if (initialCapacity < 1) {
    std::ostringstream s;
    s << "Initial capacity = " << initialCapacity << " must be > 0";
    throw illegalParameterValue(s.str());
  }

  firstNode = nullptr;
  listSize = 0;
}

template <class T>
chain<T>::chain(const chain<T>& theChain) {
  listSize = theChain.listSize;

  /// if the size is zero.
  if (listSize == 0) {
    firstNode == nullptr;
    return;
  }

  /// the head of chain
  /// node in theList to copy from.
  chainNode<T>* sourceNode = theChain.firstNode;
  /// copy first element of theList
  firstNode = new chainNode<T>(sourceNode->element);

  /// sourceNode - targetNode is one.
  /// don't use the first node, whether it come from the this->firstNode or
  /// righthand -> firstNode.
  sourceNode = sourceNode->next;
  chainNode<T>* targetNode = firstNode;

  /// copy remaining elements
  while (sourceNode != nullptr) {
    targetNode->next = new chainNode<T>(sourceNode->element);
    targetNode = targetNode->next;
    sourceNode = sourceNode->next;
  }

  /// end the chain
  targetNode->next = nullptr;
}

template <class T>
chain<T>::~chain() {
  while (firstNode != nullptr) {
    /// delete node
    chainNode<T>* nextNode = firstNode->next;
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
    }  /// p is theIndex-1.

    /// p is theIndex in the next line.
    deleteNode = p->next;
    /// skip the theIndex.
    p->next = p->next->next;
  }
  --listSize;
  delete deleteNode;
}

template <class T>
void chain<T>::insert(int theIndex, const T& theElement) {
  if (theIndex < 0 || theIndex > listSize) {
    std::ostringstream s;
    s << "index = " << theIndex << " size = " << listSize;
    throw illegalIndex(s.str());
  }

  /// insert in the head
  if (theIndex == 0) {
    firstNode = new chainNode<T>(theElement, firstNode);
  }
  /// insert in not head
  else {
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
    out << currentNode->element << "  ";
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
std::ostream& operator<<(std::ostream& out, const chain<T>& x) {
  x.output(out);
  return out;
}

#endif  // CHAIN_H
