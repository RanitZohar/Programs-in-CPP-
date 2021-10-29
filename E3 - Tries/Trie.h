#pragma once
#include"TrieNode.h"
#include<string>
using namespace std;

class Trie
{
public:
	const int alphabet = 26;  //size of the English`s alphabet
	TrieNode* root;  // pointer to a  type TrieNode variable  
	Trie() { root = new TrieNode(); };  //c-tor


	void insertWord(string str);   // The function add a new string to the database (the function will get a string and add it to the tree)
	bool deleteWord(string str);   // The function Deleting an existing string from the repository (the function will get a string and delete it from the tree according to the various options)
	bool searchWord(string str);   // The function Search whether a string exists in the database (a function will get a search string)
	int printAllWordFromPrefix(string str); // The function obtaining a pointer to a vertex in the repository and printing all the strings stored in the sub-tree starting from that vertex (all the strings starting from the same vertex), as a word-for-word list, in lexicographic order.if the words not exist the func will return 0
	bool isLeaf(TrieNode* node); // Check if the node is a leaf
	void printRecursive(TrieNode* node, string str);// the function get node and string and print all the words that ther prefix is the string that send




};

