#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <algorithm>
#include <iterator>
#include <sstream>

#include "changelength1d.h"
#include "linearlist.h"
#include "myExceptions.h"

template <class T>
class arrayList : public linearList<T> {
 public:
  /** 
   * @brief 默认的构造函数
   * @param initialCapacity 表的初始容量
   * 
   * @return 
   */
  arrayList(int initialCapacity = 10);
  /** 
   * @brief 拷贝构造函数
   * @param theList  
   * 
   * @return 
   */
  arrayList(const arrayList<T>& theList);
  /** 
   * 析构函数
   * 删除数组的内容
   * 
   * @return 
   */
  ~arrayList() { delete[] element; }

  /// ADT method
  /** 
   * 检查listSize的大小。
   * 
   * 
   * @return 
   */
  bool empty() const { return listSize == 0; }
  /** 
   * 返回list的大小
   * 
   * 
   * @return 
   */
  int size() const { return listSize; }
  T& get(int theIndex) const;
  int indexOf(const T& theElement) const;
  void erase(int theIndex);
  void insert(const int theIndex, const T& theElement);
  void output(std::ostream& out) const;

  int capacity() const { return arrayLength; }

 protected:
  void checkIndex(int theIndex) const;
  T* element;
  int arrayLength;
  int listSize;
};

template <class T>
arrayList<T>::arrayList(int initialCapacity) {
  if (initialCapacity < 1) {
    std::ostringstream s;
    s << "Initial capacity = " << initialCapacity << " must be > 0";
    throw illegalParameterValue(s.str());
  }

  arrayLength = initialCapacity;
  element = new T[arrayLength];
  listSize = 0;
}

template <class T>
arrayList<T>::arrayList(const arrayList<T>& theList) {
  arrayLength = theList.arrayLength;
  listSize = theList.listSize;
  element = new T[arrayLength];
  std::copy(theList.element, theList.element + listSize, element);
}

template <class T>
T& arrayList<T>::get(int theIndex) const {
  checkIndex(theIndex);
  return element[theIndex];
}

template <class T>
int arrayList<T>::indexOf(const T& theElement) const {
  int theIndex = static_cast<int>(
      std::find(element, element + listSize, theElement) - element);

  if (theIndex == listSize) {
    return -1;
  } else {
    return theIndex;
  }
}

template <class T>
void arrayList<T>::erase(int theIndex) {
  checkIndex(theIndex);

  std::copy(element + theIndex + 1, element + listSize, element + theIndex);
  --listSize;
  element[listSize].~T();
}

template <class T>
void arrayList<T>::insert(const int theIndex, const T& theElement) {
  if (theIndex < 0 || theIndex > listSize) {
    std::ostringstream s;
    s << "index = " << theIndex << " size = " << listSize;
    throw illegalIndex(s.str());
  }

  if (listSize == arrayLength) {
    changeLength1D(element, arrayLength, 2 * arrayLength);
    arrayLength = 2 * arrayLength;
  }

  std::copy_backward(element + theIndex, element + listSize,
                     element + listSize + 1);

  element[theIndex] = theElement;
  listSize = listSize + 1;
}

template <class T>
void arrayList<T>::output(std::ostream& out) const {
  std::copy(element, element + listSize, std::ostream_iterator<T>(out, "  "));
}

template <class T>
void arrayList<T>::checkIndex(int theIndex) const {
  if (theIndex < 0 || theIndex >= listSize) {
    std::ostringstream s;
    s << "index = " << theIndex << " size = " << listSize;
    throw illegalIndex(s.str());
  }
}

template <class T>
std::ostream& operator<<(std::ostream& out, const arrayList<T>& x) {
  x.output(out);
  return out;
}

#endif  // ARRAYLIST_H
