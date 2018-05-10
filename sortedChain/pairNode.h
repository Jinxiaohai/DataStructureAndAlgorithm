////////////////////////////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// COPYRIGHT (c) 2018, 金小海
/// All rights reserved.
///
/// @file    This file is part of the sortedChain project.
/// @version 1.0
/// @author  jinxiaohai <jinxiaohaijin@outlook.com>
/// @date    2018 05 09    16:12:31
/// @brief   the node of sortedChain.
///
/// 修订说明:最初版本
////////////////////////////////////////////////////////////////////////
#ifndef PAIRNODE_H
#define PAIRNODE_H

#include <utility>

template <class K, class E>
class pairNode {
 public:
  /// 定义pairNode里面的元素的类型
  typedef std::pair<const K, E> pairType;
  pairType element;
  pairNode<K, E>* next;

  pairNode(const pairType& thePair) : element(thePair) {}
  pairNode(const pairType& thePair, pairNode<K, E>* theNext)
      : element(thePair) {
    next = theNext;
  }
};

#endif  // PAIRNODE_H
