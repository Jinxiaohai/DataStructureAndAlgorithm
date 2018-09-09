#include <string>

#include "function.h"

int stringToInt(std::string &s) {
  int length = static_cast<int>(s.length());
  int answer = 0;

  if (length % 2 == 1) {
    answer = s.at(length - 1);
    --length;
  }

  for (int i = 0; i != length; i += 2) {
    answer += s.at(i);
    answer += static_cast<int>(s.at(i + 1)) << 8;
  }

  return (answer < 0) ? -answer : answer;
}
