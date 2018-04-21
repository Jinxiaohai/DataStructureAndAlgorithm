#ifndef EXTENDEDCHAIN_H
#define EXTENDEDCHAIN_H

#include <iostream>
#include <sstream>
#include <string>
#include "chainwithiterator.h"
#include "extendedlinear.h"
#include "myExceptions.h"

using namespace std;

template <class T>
class extendedChain : public extendedLinearList<T>, public chain<T> {
 public:
  extendedChain(int initialCapacity = 10) : chain<T>(initialCapacity) {}
  extendedChain(const extendedChain<T>& c) : chain<T>(c) {}

  bool empty() const { return listSize == 0; }
  int size() const { return listSize; }
  void erase(int theIndex);
  void insert(int theIndex, const T& theElement);
  void clear() {
    while (firstNode != nullptr) {
      chainNode<T>* nextNode = firstNode->next;
      delete firstNode;
      firstNode = nextNode;
    }
  }
  void push_back(const T& theElement);
  void zero() {
    firstNode = nullptr;
    listSize = 0;
  }

 protected:
  chainNode<T>* lastNode;
};

template <class T>
void extendedChain<T>::erase(int theIndex) {
  checkIndex(theIndex);
}
#endif  // EXTENDEDCHAIN_H
