#include "SuccinctTree.h"
#include <iostream>
int main() {

  // std::vector<int> v1({0, 1, 2});
  // std::vector<int> v2({3, 4});
  //
  // v1.insert(v1.end(), v2.begin(), v2.end());

  SuccinctTree ID = SuccinctTree::Construct("[1000,0100,0010,0001]");
  SuccinctTree second = SuccinctTree::Construct("[0011,0110,1100,1100]");
  //
//  SuccinctTree result = ID + second;
  std::cout << ID << "\n";
   std::cout << second << "\n";


  // std::cout << result << "\n";
}
