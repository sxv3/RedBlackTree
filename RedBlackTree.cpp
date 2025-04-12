#include "RedBlackTree.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

RedBlackTree::RedBlackTree() {
    root = 0;
}

void RedBlackTree::leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if (y->left != 0) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == 0) {
        root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void RedBlackTree::rightRotate(Node* x) {
    Node* y = x->left;
    x->left = y->right;
    if (y->right != 0) {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == 0) {
        root = y;
    } else if (x == x->parent->right) {
        x->parent->right = y;
    } else {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}
