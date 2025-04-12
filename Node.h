#ifndef NODE_H
#define NODE_H

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
