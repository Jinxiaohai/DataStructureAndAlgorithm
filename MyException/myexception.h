/**
  * \file myexception.h
  * \brief exception
  *
  *  excetions
  *
  * \author jinxiaohai
  * \version 1.0
  * \date 2018
  */

#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <string>

/// \brief XIAOHAI
///
/// This code is wrote by xiaohai.
///
namespace XIAOHAI {

/// \brief illegal parameter value
///
/// illegal parameter value
///
class illegalParameterValue {
 public:
  illegalParameterValue(const std::string& theMessage =
                            "Illegal parameter value");
  void outputMessage() const;

 private:
  std::string message;
};

/// \brief illegal input data
///
/// illegal input data
///
class illegalInputData {
 public:
  illegalInputData(const std::string& theMessage = "Illegal data input");
  void outputMessage() const;

 private:
  std::string message;
};

/// \brief illegal index
///
/// illegal index
///
class illegalIndex {
 public:
  illegalIndex(const std::string& theMessage = "Illegal index");
  void outputMessage() const;

 private:
  std::string message;
};

/// \brief matrix index out of bounds
///
/// matrix index out of bounds
///
class matrixIndexOutOfBounds {
 public:
  matrixIndexOutOfBounds(const std::string& theMessage =
                             "Matrix index out of bounds");
  void outputMessage() const;

 private:
  std::string message;
};

/// \brief matrix size mismatch
///
/// matrix size mismatch
///
class matrixSizeMismatch {
 public:
  matrixSizeMismatch(const std::string theMessage =
                         "The size of the two matrics doesn't match");
  void outputMessage() const;

 private:
  std::string message;
};

/// \brief stack empty
///
/// stack empty
///
class stackEmpty {
 public:
  stackEmpty(const std::string theMessage = "Invalid operation on empty stack");
  void outputMessage() const;

 private:
  std::string message;
};

/// \brief queue is empty
///
/// queue is empty
///
class queueEmpty {
 public:
  queueEmpty(const std::string theMessage = "Invalid operation on empty queue");
  void outputMessage() const;

 private:
  std::string message;
};

/// \brief hash table is full
///
/// hash table is full
///
class hashTableFull {
 public:
  hashTableFull(const std::string theMessage = "The hash table is full");
  void outputMessage() const;

 private:
  std::string message;
};

/// \brief edge weight undefined
///
/// edge weight undefined
///
class undefinedEdgeWeight {
 public:
  undefinedEdgeWeight(const std::string theMessage = "No edge weights defined");
  void outputMessage() const;

 private:
  std::string message;
};

class undefinedMethod {
 public:
  undefinedMethod(const std::string theMessage = "This method is undefined");
  void outputMessage() const;

 private:
  std::string message;
};
}

#endif  // MYEXCEPTION_H
