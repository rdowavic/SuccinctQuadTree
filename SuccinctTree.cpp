#include "SuccinctTree.h"

// let the constructor/destructor just be default for now, in fact
// I might be able to just leave it like that
SuccinctTree::SuccinctTree() : multiplier(new Multiplier()) {}
SuccinctTree::~SuccinctTree() { delete multiplier; }

SuccinctTree SuccinctTree::Construct(std::string s) {
  SuccinctTree tree;
  // figure out dimensionality from the string size
  MatrixProcessor p;
  std::string cleaned = p.strip(s);
  tree.dimension = (size_t) sqrt(cleaned.length());
  tree.insert(cleaned);
  return tree;
}

bool SuccinctTree::empty() const {
  return ruler.empty();
}

void SuccinctTree::giveChild() {
  ruler.resize(ruler.size() + NUM_CHILDREN);
}

std::ostream& operator <<(std::ostream& stream, const SuccinctTree& t) {
  stream << "[";
  for (size_t i = 0; i < t.dimension; ++i) {
    for (size_t j = 0; j < t.dimension; ++j) {
      stream << t.at(i, j);
    }
    if (i != t.dimension - 1) stream << ", ";
  }
  stream << "]";
  return stream;
}

SuccinctTree SuccinctTree::operator*(const SuccinctTree& other) {
  return multiplier->Product(*this, other); 
}


bool SuccinctTree::at(size_t i, size_t j) const {
  // deal with the case where the tree is empty
  if (ruler.empty()) return false;
  // base case is when dimension == 1 (a 1 by 1 matrix)?
  size_t dim = dimension;  
  size_t quadrant;

  for (size_t k = 0; dim > 1; k = ruler[k + quadrant], dim /= 2) {
    quadrant = quadrantNum(i, j, dim);
    if (ruler[k + quadrant] == 0)
      return false;
    // don't we need to also adjust the quadrant variable?
    if (quadrant >= 2) i -= dim / 2;
    if (quadrant % 2 == 1) j -= dim / 2;
  } 

  return true; 
}

size_t SuccinctTree::quadrantNum(size_t i, size_t j, size_t dim) const {
   int quadNum = 0;
   if (i >= dim / 2) quadNum += 2;
   if (j >= dim / 2) quadNum++;
   return quadNum; 
}


int SuccinctTree::insert(std::string child) {
  // in the base case, we need to return 0
  if (child.find('1') == std::string::npos)
    return 0;

  // need to make new item at the end
  int index = ruler.size(); // will be zero the first time
  // add 4 new entries to the back of this vector
  giveChild();
  // with meaningful values in the loop below
  MatrixProcessor p;

  for (int i = 0; i < 4; ++i) {
    std::string grandChild = p.recoverQuadrant(child, i);
    ruler[index + i] = insert(grandChild);
  }
  return index;
}
