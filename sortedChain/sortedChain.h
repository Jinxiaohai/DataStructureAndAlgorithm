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
  ///
  std::pair<const K, E>* find(const K&) const;
  void erase(const K&);
  ///
  void insert(const std::pair<const K, E>&);
  void output(std::ostream& out) const;

 protected:
  /// pointer to first node in chain
  pairNode<K, E>* firstNode;
  /// number of elements in dictionary
  int dSize;
};

template <class K, class E>
sortedChain<K, E>::sortedChain() {
  dSize = 0;
  firstNode = nullptr;
}

template <class K, class E>
sortedChain<K, E>::~sortedChain() {
  while (firstNode != nullptr) {
    pairNode<K, E>* nextNode = firstNode->next;
    delete firstNode;
    firstNode = nextNode;
  }
}

template <class K, class E>
bool sortedChain<K, E>::empty() const {
  return dSize == 0;
}

template <class K, class E>
int sortedChain<K, E>::size() const {
  return dSize;
}

template <class K, class E>
std::pair<const K, E>* sortedChain<K, E>::find(const K& theKey) const {
  pairNode<K, E>* currentNode = firstNode;

  while (currentNode != nullptr && (currentNode->element).first != theKey) {
    currentNode = currentNode->next;
  }

  if (currentNode != nullptr && (currentNode->element).first == theKey) {
    return &(currentNode->element);
  }

  return nullptr;
}

template <class K, class E>
void sortedChain<K, E>::erase(const K& theKey) {
  pairNode<K, E>* nextCurrentNode = firstNode;
  pairNode<K, E>* currentNode = nullptr;

  while (nextCurrentNode != nullptr &&
         nextCurrentNode->element.first < theKey) {
    currentNode = nextCurrentNode;
    nextCurrentNode = currentNode->next;
  }

  if (nextCurrentNode != nullptr && nextCurrentNode->element.first == theKey) {
    if (currentNode == nullptr) {
      firstNode = nextCurrentNode->next;
    } else {
      currentNode->next = nextCurrentNode->next;
    }

    delete nextCurrentNode;
    --dSize;
  }
}

template <class K, class E>
void sortedChain<K, E>::insert(const std::pair<const K, E>& thePair) {
  pairNode<K, E>* p = firstNode;
  pairNode<K, E>* tp = nullptr;

  while (p != nullptr && p->element.first < thePair.first) {
    tp = p;
    p = p->next;
  }

  if (p != nullptr && p->element.first == thePair.first) {
    p->element.second = thePair.second;
    return;
  }

  pairNode<K, E>* newNode = new pairNode<K, E>(thePair, p);

  if (tp == nullptr) {
    firstNode = newNode;
  } else {
    tp->next = newNode;
  }
  ++dSize;
  return;
}

template <class K, class E>
void sortedChain<K, E>::output(std::ostream& out) const {
  for (pairNode<K, E>* currentNode = firstNode; currentNode != nullptr;
       currentNode = currentNode->next) {
    out << currentNode->element.first << "   " << currentNode->element.second
        << "  ";
  }
}

template <class K, class E>
std::ostream& operator<<(std::ostream& out,
                         const sortedChain<K, E>& theSortedChain) {
  theSortedChain.output(out);
  return out;
}

#endif  // SORTEDCHAIN_H
