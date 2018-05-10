////////////////////////////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// COPYRIGHT (c) 2018, 金小海
/// All rights reserved.
///
/// @file    This file is part of the hashTable project.
/// @version 1.0
/// @author  jinxiaohai <jinxiaohaijin@outlook.com>
/// @date    2018 05 10    13:12:51
/// @brief   hash table using linear open addressing and division implements
///          dictionary methods other than erase
///
/// 修订说明:最初版本
////////////////////////////////////////////////////////////////////////
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>

#include "hash.h"
#include "myExceptions.h"

template <class K, class E>
class hashTable {
 public:
  hashTable(int theDivisor = 11);
  ~hashTable();

  /// ADTs
  bool empty() const;
  int size() const;
  std::pair<const K, E> *find(const K &) const;
  void insert(const pair<const K, E> &);
  void output(std::ostream &out) const;

 protected:
  int search(const K &) const;
  /// hash table
  std::pair<const K, E> **table;
  /// maps type K to nonnegative integer
  hash<K> hash;
  /// number os pairs in dictionary
  int dSize;
  /// hash function divisor
  int divisor;
};

template <class K, class E>
hashTable<K, E>::hashTable(int theDivisor) {
  divisor = theDivisor;
  dSize = 0;

  table = new pair<const K, E> *[divisor];
  for (int i = 0; i != divisor; ++i) {
    table[i] = nullptr;
  }
}

template <class K, class E>
hashTable<K, E>::~hashTable() {
  delete[] table;
}

template <class K, class E>
bool hashTable<K, E>::empty() const {
  return dSize == 0;
}

template <class K, class E>
int hashTable<K, E>::size() const {
  return dSize;
}

template <class K, class E>
std::pair<const K, E> *hashTable<K, E>::find(const K &theKey) const {
  int b = search(theKey);

  if (table[b] == nullptr || table[b]->first != theKey) {
    return nullptr;
  }

  return table[b];
}

template <class K, class E>
void hashTable<K, E>::insert(const pair<const K, E> &thePair) {
  int b = search(thePair.first);

  if (table[b] == nullptr) {
    table[b] = new pair<const K, E>(thePair);
    ++dSize;
  } else {
    if (table[b]->first == thePair.first) {
      table[b]->second = thePair.second;
    } else {
      throw hashTableFull();
    }
  }
}

template <class K, class E>
void hashTable<K, E>::output(ostream &out) const {
  for (int i = 0; i != divisor; ++i) {
    if (table[i] == nullptr) {
      std::cout << " nullptr " << std::endl;
    } else {
      std::cout << table[i]->first << "   " << table[i]->second << endl;
    }
  }
}

template <class K, class E>
int hashTable<K, E>::search(const K &theKey) const {
  int i = static_cast<int>(hash(theKey)) % divisor;
  int j = i;

  do {
    if (table[j] == nullptr || table[j]->first == theKey) {
      return j;
    }
    j = (j + 1) % divisor;
  } while (j != i);

  return j;
}

template <class K, class E>
std::ostream &operator<<(std::ostream &out, const hashTable<K, E> &x) {
  x.output(out);
  return out;
}

#endif  // HASHTABLE_H
