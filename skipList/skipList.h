////////////////////////////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// COPYRIGHT (c) 2018, 金小海
/// All rights reserved.
///
/// @file    This file is part of the skipList project.
/// @version 1.0
/// @author  jinxiaohai <jinxiaohaijin@outlook.com>
/// @date    2018 05 10    10:02:39
/// @brief   skip list data structure, implements dictionary
///
/// 修订说明:最初版本
////////////////////////////////////////////////////////////////////////
#ifndef SKIPLIST_H
#define SKIPLIST_H

#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

#include "dictionary.h"
#include "myExceptions.h"
#include "skipNode.h"

template <class K, class E>
class skipList : public dictionary<K, E> {
 public:
  skipList(K, int maxPairs = 10000, double prob = 0.5);
  ~skipList();

  /// ADTs
  bool empty() const;
  int size() const;
  std::pair<const K, E> *find(const K &) const;
  void erase(const K &);
  void insert(const pair<const K, E> &);
  void output(std::ostream &out) const;

 protected:
  /// used to decide level number
  double cutOff;
  /// generate a random level number
  int level() const;
  /// max current nonempty chain
  int levels;
  /// number of pairs in dictionary
  int dSize;
  /// max permissible chain level
  int maxLevel;
  /// a large key
  K tailKey;
  /// search saving last nodes seen
  skipNode<K, E> *search(const K &) const;
  /// header node pointer
  skipNode<K, E> *headerNode;
  /// tail node pointer
  skipNode<K, E> *tailNode;
  /// last[i] = last node seen on level i
  skipNode<K, E> **last;
};

#endif  // SKIPLIST_H
