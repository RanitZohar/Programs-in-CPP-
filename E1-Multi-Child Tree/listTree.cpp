#include <iostream>
#include <list>
#include <string>
#include "Tree.h"
#include "listTree.h"
#include"Node.h"






void listTree::addNewTree(string s)
{
	this->listT.push_front(new Tree(s));

}

void listTree::deleteTree(Node* root)   
{

	std::list<Tree*>::iterator it = listT.begin();
	bool deleted = false;
	while ((it != listT.end()) && (!deleted))
	{
		if ((*it)->root->content == root->content)
		{
			listT.remove(*it);
			deleted = !deleted;
		}
		it++;
	}
	if (deleted)
		return;
	else
	{
		cout << "the pointer does not exist in the list" << endl;
	}
	

}

void listTree::searchAndPrint(string s)
{
	bool found = false;
	
	std::list<Tree*>::iterator it = listT.begin();
	while (it != listT.end())
	{
		if ((*it)->search(s) != NULL)
		{
			found = true;
			(*it)->printSearchSubTree(s);
			(*it)->printPathToRoot((*it)->search(s));
			cout << endl;
			
		}
		
		it++;
		
	}
	if (!found) {
		cout << "ERROR" << endl;
	}
}

bool listTree::addResponse(string root, string discussion, string response)
{
	std::list<Tree*>::iterator it = listT.begin();
	while (it != listT.end())
	{
		if ((*it)->root->content == root)
		{
			if ((*it)->addResponse(discussion, response))
				return true;
			else
				return false;
		}
		it++;
	}
	return false;
}

bool listTree::delResponse(string root, string discussion)
{

	std::list<Tree*>::iterator it = listT.begin();
	while (it != listT.end())
	{
		if ((*it)->root->content == root)
		{
			Node* nodeToDelete = (*it)->search(discussion);
			if (nodeToDelete == NULL) return false;
			if (nodeToDelete->content == root)
			{
				this->listT.remove(*it);
				return  true;
			}
			(*it)->clear(nodeToDelete);
			return true;
		}
		it++;
	}
	return false;
}

void listTree::printTreeFromString(string root)
{
	std::list<Tree*>::iterator it = listT.begin();
	while (it != listT.end())
	{
		if ((*it)->root->content == root)
		{
			(*it)->printAllTree();
		}
	}
}

void listTree::printSubTree(string root, string discussion)
{
	std::list<Tree*>::iterator it = listT.begin();
	while (it != listT.end())
	{
		if ((*it)->root->content == root)
		{
			if ((*it)->search(discussion) == NULL) {
				return;
			}
			(*it)->printSearchSubTree(discussion);
			if ((*it)->root->content != discussion) {
				(*it)->printPathToRoot((*it)->search(discussion));
			}
			
		}
		it++;
	}
}

void listTree::printAllTrees()
{
	int counter = 1;
	std::list<Tree*>::iterator it = listT.begin();
	while (it != listT.end())
	{
		cout << "Tree #" << counter++ << endl;
		(*it)->printAllTree();
		it++;
		cout << endl;
	}
}
