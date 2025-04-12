#include "Node.h"

//Node implementation
//by Tai Wong, 4/11/25

Node::Node(int value) {
  data = value;
  color = RED;
  left = 0;
  right = 0;
  parent = 0;
}
