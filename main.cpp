#include "RedBlackTree.h"
#include <iostream>

using namespace std;

//main.cpp for rb tree
//by Tai Wong, 4/11/25

//main function
int main() {
  RedBlackTree tree;
  int choice, value;

  cout << "1-> load from input" << endl;
  cout << "2-> add a number" << endl;
  cout << "3-> print tree" << endl;
  cout << "4->  exit" << endl;
  
  while (true) {
    cout << "enter choice: ";
    cin >> choice;
    
    if (choice == 1) {
      tree.read("input.txt");
      cout << "tree loaded from input.txt.\n";
    } else if (choice == 2) {
      cout << "enter a number (1-999): ";
      cin >> value;
      if (value >= 1 && value <= 999) {
	tree.add(value);
	cout << "value inserted \n";
      } else {
	cout << "invalid value \n";
      }
    } else if (choice == 3) {
      tree.print();
    } else if (choice == 4) {
      break;
    } else {
      cout << "invalid choice ";
    }
  }
  
  return 0;
}
