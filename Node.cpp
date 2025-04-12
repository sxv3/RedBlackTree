#include "Node.h"

Node::Node(int value) {
  data = value;
  color = RED;
  left = 0;
  right = 0;
  parent = 0;
}
