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

void RedBlackTree::fixInsert(Node* k) {
    Node* u;
    while (k->parent != 0 && k->parent->color == RED) {
        if (k->parent == k->parent->parent->right) {
            u = k->parent->parent->left;
            if (u != 0 && u->color == RED) {
                k->parent->color = BLACK;
                u->color = BLACK;
                k->parent->parent->color = RED;
                k = k->parent->parent;
            } else {
                if (k == k->parent->left) {
                    k = k->parent;
                    rightRotate(k);
                }
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                leftRotate(k->parent->parent);
            }
        } else {
            u = k->parent->parent->right;
            if (u != 0 && u->color == RED) {
                k->parent->color = BLACK;
                u->color = BLACK;
                k->parent->parent->color = RED;
                k = k->parent->parent;
            } else {
                if (k == k->parent->right) {
                    k = k->parent;
                    leftRotate(k);
                }
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                rightRotate(k->parent->parent);
            }
        }
        if (k == root) {
            break;
        }
    }
    root->color = BLACK;
}

void RedBlackTree::add(int data) {
    Node* node = new Node(data);
    Node* y = 0;
    Node* x = root;

    while (x != 0) {
        y = x;
        if (node->data < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    node->parent = y;
    if (y == 0) {
        root = node;
    } else if (node->data < y->data) {
        y->left = node;
    } else {
        y->right = node;
    }

    if (node->parent == 0) {
        node->color = BLACK;
        return;
    }

    if (node->parent->parent == 0) {
        return;
    }

    fixInsert(node);
}

void RedBlackTree::read(const char* filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Could not open file.\n";
        return;
    }

    int num;
    while (file >> num) {
        if (num > 0 && num <= 999) {
            add(num);
        }
    }
    file.close();
}

void RedBlackTree::printHelper(Node* root, const char* indent, bool last) {
    if (root != 0) {
        cout << indent;
        if (last) {
            cout << "R----";
        } else {
            cout << "L----";
        }

        cout << root->data;
        if (root->color == RED) {
            cout << "(R)";
        } else {
            cout << "(B)";
        }
        if (root->parent != 0) {
            cout << " [P: " << root->parent->data << "]";
        }
        cout << endl;

        char newIndent[256];
        strcpy(newIndent, indent);
        if (last) {
            strcat(newIndent, "     ");
        } else {
            strcat(newIndent, "|    ");
        }

        printHelper(root->left, newIndent, false);
        printHelper(root->right, newIndent, true);
    }
}

void RedBlackTree::print() {
    if (root != 0) {
        printHelper(root, "", true);
    } else {
        cout << "Tree is empty.\n";
    }
}
