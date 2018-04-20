////////////////////////////////////////////////////////////////////////
/// COPYRIGHT NOTICE
/// COPYRIGHT (c) 2017, 金小海
/// All rights reserved.
/// 
/// @file    myExceptions.h
/// @version 1.0
/// @author  jinxiaohai <jinxiaohaijin@outlook.com>
/// @date    Fri Apr 20 19:03:40 2018
/// 
/// @brief   exception classes for various error types
/// 
/// 修订说明:最初版本
////////////////////////////////////////////////////////////////////////
#ifndef myExceptions_
#define myExceptions_
#include <string>

using namespace std;

/// @brief illegal parameter value 
class illegalParameterValue {
 public:
  illegalParameterValue(string theMessage = "Illegal parameter value") {
    message = theMessage;
  }
  void outputMessage() { cout << message << endl; }

 private:
  string message;
};

/// @brief illegal input data
class illegalInputData {
 public:
  illegalInputData(string theMessage = "Illegal data input") {
    message = theMessage;
  }
  void outputMessage() { cout << message << endl; }

 private:
  string message;
};

/// @brief illegal index
class illegalIndex {
 public:
  illegalIndex(string theMessage = "Illegal index") { message = theMessage; }
  void outputMessage() { cout << message << endl; }

 private:
  string message;
};

/// @brief matrix index out of bounds
class matrixIndexOutOfBounds {
 public:
  matrixIndexOutOfBounds(string theMessage = "Matrix index out of bounds") {
    message = theMessage;
  }
  void outputMessage() { cout << message << endl; }

 private:
  string message;
};

/// @brief matrix size mismatch
class matrixSizeMismatch {
 public:
  matrixSizeMismatch(
      string theMessage = "The size of the two matrics doesn't match") {
    message = theMessage;
  }
  void outputMessage() { cout << message << endl; }

 private:
  string message;
};

/// @brief stack is empty
class stackEmpty {
 public:
  stackEmpty(string theMessage = "Invalid operation on empty stack") {
    message = theMessage;
  }
  void outputMessage() { cout << message << endl; }

 private:
  string message;
};

/// @brief queue is empty
class queueEmpty {
 public:
  queueEmpty(string theMessage = "Invalid operation on empty queue") {
    message = theMessage;
  }
  void outputMessage() { cout << message << endl; }

 private:
  string message;
};

/// @brief hash table is full
class hashTableFull {
 public:
  hashTableFull(string theMessage = "The hash table is full") {
    message = theMessage;
  }
  void outputMessage() { cout << message << endl; }

 private:
  string message;
};

/// @brief edge weight undefined
class undefinedEdgeWeight {
 public:
  undefinedEdgeWeight(string theMessage = "No edge weights defined") {
    message = theMessage;
  }
  void outputMessage() { cout << message << endl; }

 private:
  string message;
};

/// @brief method undefined
class undefinedMethod {
 public:
  undefinedMethod(string theMessage = "This method is undefined") {
    message = theMessage;
  }
  void outputMessage() { cout << message << endl; }

 private:
  string message;
};
#endif
