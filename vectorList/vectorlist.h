#ifndef VECTORLIST_H
#define VECTORLIST_H

#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
#include "linearlist.h"
#include "myExceptions.h"

template <class T>
class vectorList : public linearList<T> {
 public:
  vectorList(int initialCapacity = 10);
  vectorList(const vectorList<T>& theList);
  ~vectorList() { delete element; }

  bool empty() const { return element->empty(); }
  int size() const { return static_cast<int>(element->size()); }
  T& get(int theIndex) const;
  int indexOf(const T& theElement) const;
  void erase(int theIndex);
  void insert(int theIndex, const T& theElement);
  void output(std::ostream& out) const;

  int capacity() const { return static_cast<int>(element->capacity()); }

  typedef typename vector<T>::iterator iterator;
  iterator begin() { return element->begin(); }
  iterator end() { return element->end(); }

 protected:
  void checkIndex(int theIndex) const;
  vector<T>* element;
};

template <class T>
vectorList<T>::vectorList(int initialCapacity) {
  if (initialCapacity < 1) {
    std::ostringstream s;
    s << "Initial capacity = " << initialCapacity << " must be > 0";
    throw illegalParameterValue(s.str());
  }

  element = new vector<T>;
  element->reserve(initialCapacity);
}

template <class T>
vectorList<T>::vectorList(const vectorList<T>& theList) {
  element = new vector<T>(*theList.element);
}

template <class T>
T& vectorList<T>::get(int theIndex) const {
  checkIndex(theIndex);
  return (*element)[theIndex];
}

template <class T>
int vectorList<T>::indexOf(const T& theElement) const {
  int theIndex = static_cast<int>(
      find(element->begin(), element->end(), theElement) - element->begin());
  if (theIndex == size()) {
    return -1;
  } else {
    return theIndex;
  }
}

template <class T>
void vectorList<T>::erase(int theIndex) {
  checkIndex(theIndex);
  element->erase(begin() + theIndex);
}

template <class T>
void vectorList<T>::insert(int theIndex, const T& theElement) {
  if (theIndex < 0 || theIndex > size()) {
    std::ostringstream s;
    s << "index = " << theIndex << " size = " << size();
    throw illegalIndex(s.str());
  }
  element->insert(element->begin() + theIndex, theElement);
}

template <class T>
void vectorList<T>::output(ostream& out) const {
  std::copy(element->begin(), element->end(),
            std::ostream_iterator<T>(out, "   "));
}

template <class T>
void vectorList<T>::checkIndex(int theIndex) const {
  if (theIndex < 0 || theIndex >= size()) {
    std::ostringstream s;
    s << "index = " << theIndex << " size = " << size();
    throw illegalIndex(s.str());
  }
}

template <class T>
std::ostream& operator<<(std::ostream& out, const vectorList<T>& x) {
  x.output(out);
  return out;
}

#endif  // VECTORLIST_H
