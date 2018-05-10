////////////////////////////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// COPYRIGHT (c) 2018, 金小海
/// All rights reserved.
///
/// @file    This file is part of the skipNode project.
/// @version 1.0
/// @author  jinxiaohai <jinxiaohaijin@outlook.com>
/// @date    2018 05 10    09:41:19
/// @brief   node type used in skip lists
///          node with a next and element field,
///          elelment is a pair<const K, E>
///          next is a 1D array of pointers
///
/// 修订说明:最初版本
////////////////////////////////////////////////////////////////////////
#ifndef SKIPNODE_H
#define SKIPNODE_H

#include <utility>

template <class K, class E>
class skipNode {
 public:
  typedef std::pair<const K, E> pairType;
  pairType element;
  /// 1D array of pointers
  skipNode<K, E>** next;

  skipNode(const pairType& thePair, int size) : element(thePair) {
    /// use next[i] to describe the ith level pointer.
    next = new skipNode<K, E>*[size];
  }
};

#endif  // SKIPNODE_H
