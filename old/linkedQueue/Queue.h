///----------------------------------------------------------------------------
/// \brief abstract class queue
///        abstract data type specification for queue data structure
///        all methods are pure virtual functions
/// \author xiaohaijin@outlook.com jinxiaohai
/// \date 2018/05/09
/// \version 1.0
///----------------------------------------------------------------------------
#ifndef QUEUE_H
#define QUEUE_H

template <class T>
class queue {
 public:
  virtual ~queue() {}
  virtual bool empty() const = 0;
  virtual int size() const = 0;
  virtual T& front() = 0;
  virtual T& back() = 0;
  virtual void pop() = 0;
  virtual void push(const T& theElement) = 0;
};

#endif  // QUEUE_H
