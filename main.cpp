#include "SuccinctTree.h"
#include <iostream>
int main() {
  SuccinctTree first = SuccinctTree::Construct("[1000,0100,0010,0001]");
  SuccinctTree second = SuccinctTree::Construct("[1111,1111,1111,1111]");

  std::cout << first + second << "\n";
  std::cout << first * second << "\n";

  // std::cout << t << "\n";
}
