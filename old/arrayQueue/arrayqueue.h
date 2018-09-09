////////////////////////////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// COPYRIGHT (c) 2018, 金小海
/// All rights reserved.
///
/// @file    This file is part of the arrayQueue project.
/// @version 1.0
/// @author  jinxiaohai <jinxiaohaijin@outlook.com>
/// @date    2018 05 09    09:04:51
/// @brief   The class was created to simulate the queue.
///          对于变量queueFront的约定，我们约定沿着逆时针方向，
///          指向队列首元素的下一个位置。对于queueBack仍然是最后一个元素。
///          映射关系为 ：location(i) = (location(queueFront)+i) % arrayLength
///
/// 修订说明:最初版本
////////////////////////////////////////////////////////////////////////
#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include <sstream>

#include "Queue.h"
#include "myExceptions.h"

template <class T>
class arrayQueue : public queue<T> {
 public:
  arrayQueue(int initialCapacity = 10);
  virtual ~arrayQueue();

  bool empty() const;
  int size() const;
  T& front();
  T& back();
  void pop();
  void push(const T& theElement);

 private:
  int theFront;
  int theBack;
  int arrayLength;
  T* queue;
};

template <class T>
arrayQueue<T>::arrayQueue(int initialCapacity) {
  if (initialCapacity < 1) {
    std::ostringstream s;
    s << "Initial capacity = " << initialCapacity << " must be > 0";
    throw illegalParameterValue(s.str());
  }

  /// if the queue is empty, theFront = theBack.
  /// if the queue is full, the size is arrayLength - 1.
  theFront = 0;
  theBack = 0;
  arrayLength = initialCapacity;
  queue = new T[arrayLength]();
}

template <class T>
arrayQueue<T>::~arrayQueue() {
  delete[] queue;
}

/// 检测队列为空。
template <class T>
bool arrayQueue<T>::empty() const {
  return theBack == theFront;
}

/// 检测队列的大小。
template <class T>
int arrayQueue<T>::size() const {
  return (theBack - theFront + arrayLength) % arrayLength;
}

/// 真正的头部的元素为(theFront+1)%arrayLength，这个要了解下布局。
template <class T>
T& arrayQueue<T>::front() {
  if (theFront == theBack) {
    throw queueEmpty();
  }
  return queue[(theFront + 1) % arrayLength];
}

/// 尾元素是真正的尾元素。
template <class T>
T& arrayQueue<T>::back() {
  if (theFront == theBack) {
    throw queueEmpty();
  }
  return queue[theBack];
}

/// 先进先出，将theFront后移一位就行了，
/// 但是要考虑此时theFront是否在数组的最后一个元素。
template <class T>
void arrayQueue<T>::pop() {
  if (theFront == theBack) {
    throw queueEmpty();
  }
  theFront = (theFront + 1) % arrayLength;
  /// destructor for T
  queue[theFront].~T();
}

/// 在尾部插入新的元素
template <class T>
void arrayQueue<T>::push(const T& theElement) {
  /// 先检查队列是否已经满掉
  if ((theBack + 1) % arrayLength == theFront) {
    /// 当数组已经满了，从新分配一个两倍原大小的数组。
    T* newQueue = new T[2 * arrayLength];
    /// 真正的首元素的位置(队首位置)
    int start = (theFront + 1) % arrayLength;
    /// 当theFront在原数组的最后一个位置或者为第一个元素时的拷贝处理
    /// 原数组是没有这行布局的，是真正的顺序储存着的。(无环存储)
    if (start < 2) {
      /// 待复制的元素的个数为arrayLength - 1个。
      std::copy(queue + start, queue + start + arrayLength - 1, newQueue);
    }
    /// 当原数组的布局结构中是采用折行处理时，
    /// 先拷贝theFront右边到最后这一部分，
    /// 接着拷贝theFront前面的一部分。(有环存储)
    else {
      std::copy(queue + start, queue + arrayLength, newQueue);
      std::copy(queue, queue + theBack + 1, newQueue + (arrayLength - start));
    }

    /// 新的尾元素为theFront,这是合乎情理的。
    theFront = 2 * arrayLength - 1;
    /// theBack = (arrayLength - 1) - 1,
    /// 第一部分为元素的个数，再进行减去1是因为从0进行开始的。
    theBack = arrayLength - 2;
    /// 新的长度
    arrayLength = 2 * arrayLength;
    queue = newQueue;
  }

  /// 添加新的元素
  theBack = (theBack + 1) % arrayLength;
  queue[theBack] = theElement;
}

#endif  // ARRAYQUEUE_H
