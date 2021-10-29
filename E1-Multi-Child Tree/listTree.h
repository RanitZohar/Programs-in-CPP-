#pragma once
#include <iostream>
#include <string>
#include <list>
#include "Node.h"
#include "Tree.h"
class listTree
{
public:
	list<Tree*> listT;


	listTree() {  } //Default constructor
	~listTree() {
		this->listT.clear();
	}  //destructor
	void addNewTree(string s);// The function receives a string-type variable and adds a tree-type member to the list
	void deleteTree(Node* root); // The function receives a Node-type variable and delete it from the list
	void searchAndPrint(string s); // The function receives a string-type variable and search and print the path for this response and the path to it
	bool addResponse(string root, string discussion, string response);// The function gets the string of the tree root, the string that the user wants to comment on, and its new response, and adds it
	bool delResponse(string root, string discussion);//The function gets the string of the tree root, and the string it wants to delete and the function will search and delete it
	void printTreeFromString(string root); //The function takes a string that is the root of a tree and prints the entire tree, hierarchically.
	void printSubTree(string root, string discussion);//The function receives a string of a tree and a string of a response /discussion, and prints the tree from the sub-tree of that response, in a hierarchical manner.
	void printAllTrees(); //The function print all the trees in the list
};

