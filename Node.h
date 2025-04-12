#ifndef NODE_H
#define NODE_H

//node header file
//by Tai Wong, 4/11/25

enum Color { RED, BLACK };

class Node {
public:
  int data;
  Color color;
  Node* left;
  Node* right;
  Node* parent;

  Node(int value);
};

#endif
