#include <string>

#include "functionDeclaration.h"

long threeToLong(std::string &s) {
  long answer = s.at(0);
  answer = (answer << 8) + s.at(1);
  answer = (answer << 8) + s.at(2);

  return answer;
}
