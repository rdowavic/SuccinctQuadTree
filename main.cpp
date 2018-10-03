#include "SuccinctTree.h"
#include <iostream>
int main() {
  SuccinctTree ID = SuccinctTree::Construct("[1000,0100,0010,0001]");
  SuccinctTree second = SuccinctTree::Construct("[0011,0110,1100,1100]");

  SuccinctTree result = ID * second;
  std::cout << result << "\n";


  // std::cout << t << "\n";
}
