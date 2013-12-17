#include <iostream>
#include <string>
#include <cstdlib>
#include "bst.h"

using namespace std;
using namespace cop4530;

int main()
{
  
    string input;
    
    // get a list of integer values
    cout << endl;
    cout << "Enter a list of integer values in one line: ";
    getline(cin, input);

    // create a binary search tree
    BST<int> bst1(input);
    if (!bst1.empty()) {
	cout << endl;
    	cout << "Inorder traversal: ";
    	bst1.printInOrder();
	cout << endl;
    	cout << "Level order traversal: ";
	bst1.printLevelOrder();
	cout << endl;

    	// test copy constructor
    	BST<int> bst2(bst1);
    	cout << "Testing copy constructor: ";
    	bst2.printLevelOrder();
	cout << endl;

    	// test assignment operator
    	BST<int> bst3;
    	bst3 = bst1;
    	cout << "Testing assignment operator: ";
    	bst3.printLevelOrder();
	cout << endl;
     }

    // get a list of string values
cout << input << endl;    
cout << "Enter a list of string values in one line: ";
    getline(cin, input);
    cout << input << endl;
    // create a binary search tree
    BST<string> bsts1(input);
    if (!bsts1.empty()) {
    	cout << "Inorder traversal: ";
    	bsts1.printInOrder();
	cout << endl;
    	cout << "Level order traversal: ";
	bsts1.printLevelOrder();
	cout << endl;

    	// test copy constructor
    	BST<string> bst2(bsts1);
    	cout << "Testing copy constructor: ";
    	bst2.printLevelOrder();
	cout << endl;

    	// test assignment operator
    	BST<string> bst3;
    	bst3 = bsts1;
    	cout << "Testing assignment operator: ";
    	bst3.printLevelOrder();
	cout << endl;
     }

    cout << "Enter a list of integer values: ";
    getline(cin, input);
    bst1.buildFromInputString(input);
    cout << "Level order traversal: ";
    bst1.printLevelOrder();
    cout << endl;

    cout << "\n===================\n";
    cout << "Operation Manual:" << endl;
    cout << "d: delete value;\ti: insert value;" << endl;
    cout << "h: height of tree; \tn: number of nodes" << endl;
    cout << "o: in order print; \tl: level order print" << endl;
    cout << "s: search value;\tq: quit" << endl;
    cout << "===================\n";
    cout << "choice: ";
    int tmp;
    while (getline(cin, input)) {
        cout << input << endl;
	if (input == "q")
	    break;
	if (input == "d") {
	    cout << endl << "Type value to delete: ";
	    getline(cin, input);
        tmp = atoi(input.c_str());
        cout << tmp << endl;
	    bst1.remove(tmp);
	} else if (input == "i") {
	    cout << endl << "Type value to insert: ";
	    getline(cin, input);
        tmp = atoi(input.c_str());
        cout << tmp << endl;
	    bst1.insert(tmp);
	} else if (input == "o") {
	    cout << endl << "In order traversal: ";
	    bst1.printInOrder();
	} else if (input == "l") {
	    cout << endl << "Level order traversal: ";
	    bst1.printLevelOrder();
	} else if (input == "h") {
	    cout << endl << "Height: ";
	    cout << endl << bst1.height() << endl;
	} else if (input == "n") {
	    cout << endl << "Number of nodes: ";
	    cout << endl << bst1.numOfNodes() << endl;
	} else if (input == "s") {
	    cout << endl << "Type value to search: ";
	    getline(cin, input);
        tmp = atoi(input.c_str());
        cout << tmp << endl;
	    if (bst1.contains(tmp)) {
		cout << endl << "contains " << tmp << endl;
	    } else {
		cout << endl << "does not contains " << tmp << endl;
	    }
	}

	cout << "\n===================\n";
	cout << "Operation Manual:" << endl;
	cout << "d: delete value;\ti: insert value;" << endl;
	cout << "h: height of tree; \tn: number of nodes" << endl;
	cout << "o: in order print; \tl: level order print" << endl;
	cout << "s: search value;\tq: quit" << endl;
	cout << "===================\n";
	cout << "choice: ";
    }
    return 0;
}
