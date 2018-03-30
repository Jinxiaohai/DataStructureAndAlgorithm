#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "linearlist.h"

template <class T>
class arrayList : public linearList<T> {
 public:
  arrayList();
  arrayList(const int initialCapacity);
  ~arrayList();

  int lenght() const;
  int size() const;
  bool empty() const;
  T& get(int theIndex) const;
  int indexOf(const T& theElement) const;
  void erase(int theIndex);
  void insert(int theIndex, const T& theElement);
  void output(std::ostream& out) const;

 protected:
  void checkIndex(int theIndex) const;
  T* element;
  int arrayLength;
  int listSize;
};

#endif  // ARRAYLIST_H
