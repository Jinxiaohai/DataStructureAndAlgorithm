#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <sstream>

#include "changelength1d.h"
#include "myExceptions.h"
#include "stack.h"

template <class T>
class arrayStack {
 public:
  arrayStack(int initialCapacity = 10);
  virtual ~arrayStack() { delete[] stack; }
  bool empty() const { return stackTop == -1; }
  int size() const { return stackTop + 1; }
  T& top() {
    if (stackTop == -1) {
      throw stackEmpty();
    }
    return stack[stackTop];
  }

  void pop() {
    if (stackTop == -1) {
      throw stackEmpty();
    }
    stack[stackTop].~T();
    --stackTop;
  }

  void push(const T& theElement);

 private:
  int stackTop;
  int arrayLength;
  T* stack;
};

#endif  // ARRAYSTACK_H

template <class T>
arrayStack<T>::arrayStack(int initialCapacity) {
  if (initialCapacity < 1) {
    ostringstream s;
    s << "Initial capacity = " << initialCapacity << " Must be > 0";
    throw illegalParameterValue(s.str());
  }

  arrayLength = initialCapacity;
  stack = new T[arrayLength];
  stackTop = -1;
}

template <class T>
void arrayStack<T>::push(const T& theElement) {
  if (stackTop == arrayLength - 1) {
    changeLength1D(stack, arrayLength, 2 * arrayLength);
    arrayLength *= 2;
  }
  ++stackTop;
  stack[stackTop] = theElement;
}
