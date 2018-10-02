#include <string>
#include <iostream>
#include <vector>
#include <array>
#include <stdint.h>
#include <cmath>
#include <cassert>
#include "matrixprocessor.h"

class Multiplier;
// list of constants that are facts about the dimensions, 
// nature of the matrix etc
// ie, every non-leaf always has 4 children 
const int NUM_CHILDREN = 4;
// every matrix has 'two rows' of submatrices
const int ROW_SIZE = 2;

class SuccinctTree {
public:
  SuccinctTree(); 
  /**
   * Construct is a factory method that takes a 
   * string s and constructs a Succinct Quadtree 
   * matrix from it.
   */
  SuccinctTree(const SuccinctTree& t) = default;
  static SuccinctTree Construct(std::string s);
  /**
  * empty checks if this instance of SuccinctTree
  * is empty
  */
  bool empty() const;
  friend std::ostream& operator <<(std::ostream& stream, const SuccinctTree& t);
  /**
  * giveChild adds four new entries to the SuccinctTree's ruler
  */
  void giveChild();
  /**
  * A * B computes the matrix product of the trees A and B
  */
  SuccinctTree operator*(const SuccinctTree& other);

  /**
  * insert constructs the child as necessary and then
  * returns its index so that the current index knows how to
  * refer to it. This index will always be the length of the vector
  * when the call is first made.
  */ 
  int insert(std::string child);
  ~SuccinctTree(); 
private:
  /**
  * at retrieves the boolean stored at this specific index in the matrix
  */
  bool at(size_t i, size_t j) const;
  size_t quadrantNum(size_t i, size_t j, size_t dim) const;

public:
  std::vector<uint32_t> ruler;
  size_t dimension;
  Multiplier*  multiplier;
};
