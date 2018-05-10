////////////////////////////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// COPYRIGHT (c) 2017, 金小海
/// All rights reserved.
///
/// @file    binaryTreeNode.h
/// @version 1.0
/// @author  jinxiaohai <jinxiaohaijin@outlook.com>
/// @date    Thu May 10 14:16:45 2018
///
/// @brief   其中有三个构造函数。第一个无参数，两个指针域被置为nullptr.
///          第二个有一个参数，用来初始化element,而指针域被置为nullptr.
///          第三个有三个参数，可用来初始化三个域。
///
/// 修订说明:最初版本
////////////////////////////////////////////////////////////////////////
#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H

template <class T>
struct binaryTreeNode {
  binaryTreeNode() {
    this->leftChild = nullptr;
    this->rightChild = nullptr;
  }
  binaryTreeNode(const T& theElement) {
    this->element = theElement;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
  }
  binaryTreeNode(const T& theElement, binaryTreeNode<T>* theLeftChild,
                 binaryTreeNode<T>* theRightHand)
      : element(theElement) {
    this->leftChild = theLeftChild;
    this->rightChild = theRightHand;
  }

  T element;
  binaryTreeNode<T>* leftChild;
  binaryTreeNode<T>* rightChild;
};

#endif /* BINARYTREENODE_H */
