////////////////////////////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// COPYRIGHT (c) 2018, 金小海
/// All rights reserved.
///
/// @file    chain node is used to describe the node of chain.
/// @version 1.0
/// @author  jinxiaohai <jinxiaohaijin@outlook.com>
/// @date    2018 05 09    14:56:55
/// @brief   chain node is used to describe the node of chain.
///
/// 修订说明:最初版本
////////////////////////////////////////////////////////////////////////
#ifndef CHAINNODE_H
#define CHAINNODE_H

template <class T>
struct chainNode {
  chainNode() {}
  chainNode(const T& element) { this->element = element; }
  chainNode(const T& element, chainNode<T>* next) {
    this->element = element;
    this->next = next;
  }

  /// save data
  T element;
  /// save pointer to point the next chain node
  chainNode<T>* next;
};

#endif  // CHAINNODE_H
