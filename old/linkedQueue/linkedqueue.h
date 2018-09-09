////////////////////////////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// COPYRIGHT (c) 2018, 金小海
/// All rights reserved.
///
/// @file    This file is part of the linkedQueue project.
/// @version 1.0
/// @author  jinxiaohai <jinxiaohaijin@outlook.com>
/// @date    2018 05 09    14:58:44
/// @brief   the describe of queue used the chain.
///
/// 修订说明:最初版本
////////////////////////////////////////////////////////////////////////
#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include <sstream>

#include "Queue.h"
#include "chainnode.h"
#include "myExceptions.h"

template <class T>
class linkedQueue : public queue<T> {
 public:
  linkedQueue(int initialCapacity = 10);
  ~linkedQueue();

  /// ADTs
  bool empty() const;
  int size() const;
  T& front();
  T& back();
  void pop();
  void push(const T& theElement);

 private:
  chainNode<T>* queueFront;
  chainNode<T>* queueBack;
  int queueSize;
};

template <class T>
linkedQueue<T>::linkedQueue(int initialCapacity) {
  queueFront = nullptr;
  queueSize = 0;
}

/// destructor
template <class T>
linkedQueue<T>::~linkedQueue() {
  while (queueFront != nullptr) {
    chainNode<T>* nextNode = queueFront->next;
    delete queueFront;
    queueFront = nextNode;
  }
}

template <class T>
bool linkedQueue<T>::empty() const {
  return queueSize == 0;
}

template <class T>
int linkedQueue<T>::size() const {
  return queueSize;
}

template <class T>
T& linkedQueue<T>::front() {
  if (queueSize == 0) {
    throw queueEmpty();
  }
  return queueFront->element;
}

template <class T>
T& linkedQueue<T>::back() {
  if (queueSize == 0) {
    throw queueEmpty();
  }
  return queueBack->element;
}

template <class T>
void linkedQueue<T>::pop() {
  if (queueSize == 0) {
    throw queueEmpty();
  }
  /// delete the first node in chain
  chainNode<T>* nextNode = queueFront->next;
  delete queueFront;
  queueFront = nextNode;
  --queueSize;
}

template <class T>
void linkedQueue<T>::push(const T& theElement) {
  /// the new node
  chainNode<T>* newNode = new chainNode<T>(theElement, nullptr);

  if (queueSize == 0) {
    queueFront = newNode;
  } else {
    queueBack->next = newNode;
  }
  queueBack = newNode;

  ++queueSize;
}

#endif  // LINKEDQUEUE_H
