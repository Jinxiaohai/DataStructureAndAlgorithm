////////////////////////////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// COPYRIGHT (c) 2017, 金小海
/// All rights reserved.
/// 
/// @file    changelength1d.h
/// @version 1.0
/// @author  jinxiaohai <jinxiaohaijin@outlook.com>
/// @date    Fri Apr 20 18:57:04 2018
/// 
/// @brief   修改一维数组的大小。
/// 
/// 修订说明:最初版本
////////////////////////////////////////////////////////////////////////
#ifndef CHANGELENGTH1D_H
#define CHANGELENGTH1D_H

#include <myExceptions.h>

/// @brief 修改一维数组的大小
///
/// @param a 数组的首地址
/// @param oldLength 原来的长度
/// @param newLength 新的长度
///
template <class T>
void changeLength1D(T*& a, int oldLength, int newLength) {
  if (newLength < 0) {
    throw illegalParameterValue("new Length must be > 0");
  }

  T* temp = new T[newLength];
  int number = std::min(oldLength, newLength);
  std::copy(a, a + number, temp);
  delete[] a;
  a = temp;
}

#endif  // CHANGELENGTH1D_H
