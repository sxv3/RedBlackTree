#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include "Node.h"

//redblack tree header file
//by Tai Wong, 4/11/25

class RedBlackTree {
private:
  Node* root;
  
  void leftRotate(Node* x);
  void rightRotate(Node* x);
  void fixInsert(Node* k);
  void printHelper(Node* root, const char* indent, bool last);

public:
  RedBlackTree();
  void add(int data);
  void read(const char* filename);
  void print();
};

#endif
