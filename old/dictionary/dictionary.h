////////////////////////////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// COPYRIGHT (c) 2018, 金小海
/// All rights reserved.
///
/// @file    This file is part of the dictionary project.
/// @version 1.0
/// @author  jinxiaohai <jinxiaohaijin@outlook.com>
/// @date    2018 05 09    15:49:10
/// @brief   the dictionary is the a dictionary to describe something.
///          it is not used in the real project.
///
/// 修订说明:最初版本
////////////////////////////////////////////////////////////////////////
#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <utility>

/// K is the key, E is the value.
template <class K, class E>
class dictionary {
 public:
  ///
  virtual ~dictionary() {}
  virtual bool empty() const = 0;
  virtual int size() const = 0;
  virtual std::pair<const K, E> *find(const K &) const = 0;
  virtual void erase(const K &) = 0;
  virtual void insert(const std::pair<const K, E> &) = 0;
};

#endif  // DICTIONARY_H
