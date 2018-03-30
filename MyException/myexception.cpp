#include <iostream>

#include "myexception.h"

/// \brief initial data
/// \param theMessage is the parameter
/// \return
XIAOHAI::illegalParameterValue::illegalParameterValue(
    const std::string& theMessage) {
  message = theMessage;
}

/// \brief output message
/// \param
void XIAOHAI::illegalParameterValue::outputMessage() const {
  std::cout << message << std::endl;
}

/// \brief initial data
/// \param theMessage is the parameter
/// \return
XIAOHAI::illegalInputData::illegalInputData(const std::string& theMessage) {
  message = theMessage;
}

/// \brief output message
/// \param
void XIAOHAI::illegalInputData::outputMessage() const {
  std::cout << message << std::endl;
}

/// \brief initial data
/// \param theMessage is the parameter
/// \return
XIAOHAI::illegalIndex::illegalIndex(const std::string& theMessage) {
  message = theMessage;
}

/// \brief output message
/// \param
void XIAOHAI::illegalIndex::outputMessage() const {
  std::cout << message << std::endl;
}

/// \brief initial data
/// \param theMessage is the parameter
/// \return
XIAOHAI::matrixIndexOutOfBounds::matrixIndexOutOfBounds(
    const std::string& theMessage) {
  message = theMessage;
}

/// \brief output message
/// \param
void XIAOHAI::matrixIndexOutOfBounds::outputMessage() const {
  std::cout << message << std::endl;
}

/// \brief initial data
/// \param theMessage is the parameter
/// \return
XIAOHAI::matrixSizeMismatch::matrixSizeMismatch(const std::string theMessage) {
  message = theMessage;
}

/// \brief output message
/// \param
void XIAOHAI::matrixSizeMismatch::outputMessage() const {
  std::cout << message << std::endl;
}

/// \brief initial data
/// \param theMessage is the parameter
/// \return
XIAOHAI::stackEmpty::stackEmpty(const std::string theMessage) {
  message = theMessage;
}

/// \brief output message
/// \param
void XIAOHAI::stackEmpty::outputMessage() const {
  std::cout << message << std::endl;
}

/// \brief initial data
/// \param theMessage is the parameter
/// \return
XIAOHAI::queueEmpty::queueEmpty(const std::string theMessage) {
  message = theMessage;
}

/// \brief output message
/// \param
void XIAOHAI::queueEmpty::outputMessage() const {
  std::cout << message << std::endl;
}

/// \brief initial data
/// \param theMessage is the parameter
/// \return
XIAOHAI::hashTableFull::hashTableFull(const std::string theMessage) {
  message = theMessage;
}

/// \brief output message
/// \param
void XIAOHAI::hashTableFull::outputMessage() const {
  std::cout << message << std::endl;
}

/// \brief initial data
/// \param theMessage is the parameter
/// \return
XIAOHAI::undefinedEdgeWeight::undefinedEdgeWeight(
    const std::string theMessage) {
  message = theMessage;
}

/// \brief output message
/// \param
void XIAOHAI::undefinedEdgeWeight::outputMessage() const {
  std::cout << message << std::endl;
}

/// \brief initial data
/// \param theMessage is the parameter
/// \return
XIAOHAI::undefinedMethod::undefinedMethod(const std::string theMessage) {
  message = theMessage;
}

/// \brief output message
/// \param
void XIAOHAI::undefinedMethod::outputMessage() const {
  std::cout << message << std::endl;
}
