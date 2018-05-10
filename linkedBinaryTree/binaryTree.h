////////////////////////////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// COPYRIGHT (c) 2018, 金小海
/// All rights reserved.
///
/// @file    This file is part of the binaryTree project.
/// @version 1.0
/// @author  jinxiaohai <jinxiaohaijin@outlook.com>
/// @date    2018 05 10    14:38:53
/// @brief   abstract class binary tree
///          abstract data type specification for binary trees.
///          all methods are pure virtual functions
///          T is node type
/// 修订说明:最初版本
////////////////////////////////////////////////////////////////////////
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <functional>

template <class T>
class binaryTree {
 public:
  virtual ~binaryTree() {}
  virtual bool empty() const = 0;
  virtual int size() const = 0;
  /// parameter is a pointer to a function whose return type
  /// is void and has a single argument of type T*.
  virtual void preOrder(void (*)(T*)) = 0;
  virtual void inOrder(void (*)(T*)) = 0;
  virtual void postOrder(void (*)(T*)) = 0;
  virtual void levelOrder(void (*)(T*)) = 0;
};

#endif  // BINARYTREE_H
