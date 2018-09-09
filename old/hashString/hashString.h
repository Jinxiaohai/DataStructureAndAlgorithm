////////////////////////////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// COPYRIGHT (c) 2018, 金小海
/// All rights reserved.
///
/// @file    This file is part of the hashString project.
/// @version 1.0
/// @author  jinxiaohai <jinxiaohaijin@outlook.com>
/// @date    2018 05 10    12:33:06
/// @brief   hash string.
///
/// 修订说明:最初版本
////////////////////////////////////////////////////////////////////////
#ifndef HASHSTRING_H
#define HASHSTRING_H

#include <string>

template <>
class hash<std::string> {
 public:
  size_t operator()(const std::string &theKey) const {
    unsigned long int hashValue = 0;
    int length = static_cast<int>(theKey.length());
    for (int i = 0; i != length; ++i) {
      hashValue = 5 * hashValue + theKey.at(i);
    }
    return static_cast<size_t>(hashValue);
  }
};

#endif  // HASHSTRING_H
