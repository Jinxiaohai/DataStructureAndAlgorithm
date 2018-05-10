////////////////////////////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// COPYRIGHT (c) 2018, 金小海
/// All rights reserved.
///
/// @file    This file is part of the hashTable project.
/// @version 1.0
/// @author  jinxiaohai <jinxiaohaijin@outlook.com>
/// @date    2018 05 10    13:01:59
/// @brief   functions to convert from type K to nonnegative integer
///          derived from similar classes in SGI STL
///
/// 修订说明:最初版本
////////////////////////////////////////////////////////////////////////
#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <string>

template <class K>
class hash;

template <>
class hash<std::string> {
 public:
  size_t operator()(const std::string theKey) const {
    unsigned long hashValue = 0;
    int length = static_cast<int>(theKey.length());
    for (int i = 0; i != length; ++i) {
      hashValue = 5 * hashValue + theKey.at(i);
    }
  }
};

template <>
class hash<int> {
 public:
  size_t operator()(const int theKey) const {
    return static_cast<size_t>(theKey);
  }
};

template <>
class hash<long> {
 public:
  size_t operator()(const long theKey) const {
    return static_cast<size_t>(theKey);
  }
};

#endif  // HASH_H
