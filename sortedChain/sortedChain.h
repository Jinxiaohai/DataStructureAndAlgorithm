////////////////////////////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// COPYRIGHT (c) 2018, 金小海
/// All rights reserved.
///
/// @file    This file is part of the sortedChain project.
/// @version 1.0
/// @author  jinxiaohai <jinxiaohaijin@outlook.com>
/// @date    2018 05 09    16:42:21
/// @brief   sorted chain, implements dictionary
///
/// 修订说明:最初版本
////////////////////////////////////////////////////////////////////////
#ifndef SORTEDCHAIN_H
#define SORTEDCHAIN_H

#include <iostream>

#include "dictionary.h"
#include "pairNode.h"

template <class K, class E>
class sortedChain : public dictionary<K, E> {
 public:
  sortedChain();
  ~sortedChain();

  bool empty() const;
  int size() const;
  std::pair<const K, E>* find(const K&) const;
  void erase(const K&);
  void insert(const std::pair<const K, E>&);
  void output(std::ostream& out) const;

 protected:
  /// pointer to first node in chain
  pairNode<K, E>* firstNode;
  /// number of elements in dictionary
  int dSize;
};

#endif  // SORTEDCHAIN_H
