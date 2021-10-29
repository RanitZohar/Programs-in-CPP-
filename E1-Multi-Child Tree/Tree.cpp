#include <iostream>
#include <list>
#include <string>
#include "Tree.h"
#include "listTree.h"
#include"Node.h"









Node * Tree::search(string value)
{

	if (this->root->content == "")
	{
		return NULL;
	}
	return searchFromNode(this->root, value);
}

Node * Tree::searchFromNode(Node* n, string value)
{
	if (n->content == value)
	{
		return n;
	}
	
	std::list<Node*>::iterator it = n->responses.begin();
	Node* result = NULL;
	while (it != n->responses.end() && result == NULL ) {
	 result = searchFromNode(*it, value);
	 it++;
	}
	
			
	return result;
}

Node* Tree::searchFather(Node* current,Node* son)
{
	Node* father = NULL;
	bool found = false;
	std::list<Node*>::iterator it = current->responses.begin();
	while (it != current->responses.end())
	{
		if ((*it)->content == son->content)
			found = true;
		it++;
	}

	if (found)
		return current;
	else
	{
		std::list<Node*>::iterator it = current->responses.begin();
		while (it != current->responses.end() && father == NULL)
		{
			father = searchFather(*it, son);
			it++;
		}
	}
	return father;
}

bool Tree::addResponse(string dadResponse, string childResponse)
{
	Node* dadN = search(dadResponse);
	if (dadN== NULL)
	{
		return false;

	}
	dadN->responses.push_back(new Node(childResponse));
	return true;

}


void Tree::clear(Node * n)
{
	
	Node* father = searchFather( this->root, n);
	n->responses.clear();
	father->responses.remove(n);
	delete n;
	
}

void Tree::printAllTree()
{
	
	if (this->root) {
		printSubTree(this->root, 0);
	}
	else
	{
		cout << "empty tree" << endl;
	}
}

void Tree::printSubTree(Node * n, int count)
{
	cout << n->content << endl;
	count += 3;
	for (std::list<Node*>::iterator it = n->responses.begin(); it != n->responses.end(); it++) 
	{
		for (int i = 0; i < count; i++) {
			cout << " ";
		}
		printSubTree(*it, count);
	}
}

void Tree::printPath(string s)
{
	if (!search(s))
	{
		//cout << "there is not such as response" << endl;
		return;
	}
	printFromNode(this->root, s, 0);
	

}

void Tree::printFromNode(Node * n, string s, int count)
{
	count += 3;
	if (n->content != s) {
		cout << n->content << endl;
		for (std::list<Node*>::iterator it = n->responses.begin(); it != n->responses.end(); it++) {
			for (int i = 0; i < count; i++) {
				cout << " ";
			}
			printFromNode(*it, s, count);
		}
	}

	return;

}

void Tree::printSearchSubTree(string s)
{
	Node* n = search(s);
	if (!n)
	{
		
		return;
	}
	printSubTree(n);
}



void Tree::printPathToRoot(Node* n)
{
	cout << n->content ;
	if (this->root->content != n->content)
	{
		cout << "=>";
		printPathToRoot(searchFather(this->root, n));
	}
	
}





Tree::~Tree()
{
	clear(this->root);
}
