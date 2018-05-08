///-----------------------------------------------------
/// \brief match parentheses
/// \author xiaohai
/// \date 2018/5/8
///-----------------------------------------------------

#include <iostream>
#include <string>

#include "arrayStack.h"
#include "functionhead.h"

using namespace std;

void printMatchedPairs(string &expr) {
  arrayStack<int> s;
  int length = static_cast<int>(expr.size());

  /// match expr for ( and )
  for (int i = 0; i != length; ++i) {
    if (expr.at(i) == '(') {
      s.push(i);
    } else {
      if (expr.at(i) == ')') {
        try {
          cout << s.top() << ' ' << i << endl;
          s.pop();
        } catch (stackEmpty) {
          cout << "No match for right parenthesis at " << i << endl;
        }
      }
    }
  }

  while (!s.empty()) {
    cout << "No match for left parenthesis at " << s.top() << endl;
    s.pop();
  }
}
