#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include <sstream>

#include "chainnode.h"
#include "myExceptions.h"
#include "stack.h"

template <class T>
class linkedStack : public stack<T> {
 public:
  linkedStack(int initialCapacity = 10);
  ~linkedStack();

  /// ADTs
  bool empty() const;
  int size() const;
  T& top();
  void pop();
  void push(const T& theElement);

 private:
  chainNode<T>* stackTop;
  int stackSize;
};

template <class T>
linkedStack<T>::linkedStack(int initialCapacity) {
  stackTop = nullptr;
  stackSize = 0;
}

///
/// \brief delete the stack.
///
template <class T>
linkedStack<T>::~linkedStack() {
  while (stackTop != nullptr) {
    chainNode<T>* nextNode = stackTop->next;
    delete stackTop;
    stackTop = nextNode;
  }
}

template <class T>
bool linkedStack<T>::empty() const {
  return stackSize == 0;
}

template <class T>
int linkedStack<T>::size() const {
  return stackSize;
}

template <class T>
T& linkedStack<T>::top() {
  if (stackSize == 0) {
    throw stackEmpty();
  }
  return stackTop->element;
}

template <class T>
void linkedStack<T>::pop() {
  if (stackSize == 0) {
    throw stackEmpty();
  }

  chainNode<T>* nextNode = stackTop->next;
  delete stackTop;
  stackTop = nextNode;
  --stackSize;
}

template <class T>
void linkedStack<T>::push(const T& theElement) {
  stackTop = new chainNode<T>(theElement, stackTop);
  ++stackSize;
}

#endif  // LINKEDSTACK_H
