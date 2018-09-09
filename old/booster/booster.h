#ifndef BOOSTER_H
#define BOOSTER_H

#include <iostream>

struct booster {
  int degradeToLeaf;
  int degradeFromParent;
  bool boosterHere;

  void output(std::ostream &out) const {
    out << boosterHere << "  " << degradeToLeaf << "  " << degradeFromParent
        << "  ";
  }
};

/// overload <<
std::ostream &operator<<(std::ostream &out, booster x) {
  x.output(out);
  return out;
}

#endif  // BOOSTER_H
