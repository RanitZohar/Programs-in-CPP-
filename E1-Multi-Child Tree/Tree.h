#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Node.h"
class Tree
{
public:
	Node* root;
	Tree() {
		if (this->root != NULL)
		{
			delete this->root;
	}
		this->root = new Node(); } //Default constructor
	Tree(string c) {
		this->root = new Node(c); }  // constructor, build a root for a tree with value
	Node* search(string value); //Receive a string and return a pointer to the Node where that string is located
	Node* searchFromNode(Node* n, string value); // Recursive function, help to "search" function
	Node* searchFather(Node* current,Node* son); // Returns the father of the discussion
	bool addResponse(string dadResponse, string childResponse); //Adding a vertex to the tree, as the son of another vertex, given 2 strings, a string of the father already in the tree and a string that should be in the new son
	void clear(Node* n);  //Delete all the sub-tree of the string
	void printAllTree();// Print the entire tree, hierarchically
	void printSubTree(Node*, int count = 0); // Recursive function, help to "printAllTree" function, print Recursivly sub-tree
	void printPath(string s); //Given a string, search for a vertex with that string, and print the route from the root to that value
	void printFromNode(Node* n, string s, int count); // Recursive function, help to "printPath" function, print Recursivly the tree until the string , hierarchically 
	void printSearchSubTree(string s); //Given a string, search for a vertex with that string, and print the route from this string untill the end
    void printPathToRoot(Node* n);  // The function receives a Node-type variable and print tha path to his root
	~Tree();  //destructor
};

