#ifndef DERIVEDLINKEDSTACK_H
#define DERIVEDLINKEDSTACK_H

#include "chain.h"
#include "myExceptions.h"
#include "stack.h"

using namespace std;

template <class T>
class derivedLinkedStack : private chain<T>, public stack<T> {
 public:
  derivedLinkedStack(int initialCapacity = 10) : chain<T>(initialCapacity) {}
  bool empty() const { return chain<T>::empty(); }
  int size() const { return chain<T>::size(); }
  T& top() {
    if (chain<T>::empty()) {
      throw stackEmpty();
    }
    return get(0);
  }
  void pop() {
    if (chain<T>::empty()) {
      throw stackEmpty();
    }
    erase(0);
  }

  void push(const T& theElement) { insert(0, theElement); }
};

#endif  // DERIVEDLINKEDSTACK_H
