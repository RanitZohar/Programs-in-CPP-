#pragma once
class TrieNode
{
public:
	TrieNode* children[26] = { 0 }; //Arry of pointers to the sons of vertex
	TrieNode* father; // Pointer to the father vertex
	bool isEndWord = false;  //A Boolean field that marks the end of a word

	TrieNode() {}; // default c-tor
};

