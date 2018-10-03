#include "SuccinctTree.h"
#include <iostream>
int main() {
  std::string s = "[1000,0100,0010,0001]";
  SuccinctTree t = SuccinctTree::Construct(s);
  for (int i = 0; i < t.ruler.size(); i++) {
    if (i % 4 == 0) std::cout << "|";
    std::cout << t.ruler[i] << " ";
  }
  std::cout << "\n";
  SuccinctTree Union = t + t;

  for (int i = 0; i < Union.ruler.size(); i++) {
    if (i % 4 == 0) std::cout << "|";
    std::cout << Union.ruler[i] << " ";
  }

  //
  // std::cout << Union << "\n";

  std::cout << "\n";
  // std::cout << t << "\n";
}
