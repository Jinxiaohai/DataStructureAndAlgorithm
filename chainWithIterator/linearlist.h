////////////////////////////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// COPYRIGHT (c) 2017, 金小海
/// All rights reserved.
/// 
/// @file    linearlist.h
/// @version 1.0
/// @author  jinxiaohai <jinxiaohaijin@outlook.com>
/// @date    Fri Apr 20 18:59:25 2018
/// 
/// @brief   抽象的线性列表，用来作为基类。
/// 
/// 修订说明:最初版本
////////////////////////////////////////////////////////////////////////
#ifndef LINEARLIST_H
#define LINEARLIST_H
#include <iostream>


template <class T>
class linearList {
 public:
  virtual ~linearList() {}
  virtual bool empty() const = 0;
  virtual int size() const = 0;
  virtual T& get(int theIndex) const = 0;
  virtual int indexOf(const T& theElement) const = 0;
  virtual void erase(int theIndex) = 0;
  virtual void insert(int theIndex, const T& theElement) = 0;
  virtual void output(std::ostream& out) const = 0;
};

#endif  // LINEARLIST_H
