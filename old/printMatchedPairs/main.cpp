#include <iostream>
#include <string>

#include "functionhead.h"

using namespace std;

int main(int argc, char *argv[]) {
  string expr;

  cout << "Type an expression" << endl;
  cin >> expr;
  cout << "The pairs of matching parenthesis in" << endl
       << expr << endl
       << "are" << endl;

  printMatchedPairs(expr);

  return 0;
}
