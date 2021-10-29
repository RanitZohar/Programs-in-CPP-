#include "Trie.h"
#include <iostream>
using namespace std;

void Trie::insertWord(string str)
{
    if (searchWord(str))
        return;
    TrieNode* current = root;
    for (int i = 0; i < str.length(); i++)
    {
        int index = str[i] - 'a';  //To know the index of the letter in the arry 
        if (current->children[index] == NULL)  //if the letter is not exist in the child
        {
            current->children[index] = new TrieNode(); // add a node from TrieNode type
            current->children[index]->father = current;
        }
      
        current = current->children[index];

    }
    current->isEndWord = true;
}

bool Trie::deleteWord(string str)
{
    if (!searchWord(str))
        return false;
    TrieNode* current = root;
    int index = 0;
    for (int i = 0; i < str.length(); i++) // Promoting the pointer of the tree to the end of the word of the string (to the last letter)     
    {
         index = str[i] - 'a'; //To know the index of the letter in the arry 
        current = current->children[index];

    }

    if (isLeaf(current))
    {
        TrieNode* temp = current->father;
        
        for (int i = 0; i < alphabet; i++)
        {
            current->children[i] = NULL;
            
        }
        delete current;
       
   
        current = temp;
        current->children[index] = NULL;
        while (current->isEndWord == false)
        {
            if (isLeaf(current))
            {
                temp = current->father;
                for (int i = 0; i < alphabet; i++)
                {
                    current->children[i] = NULL;

                }
                for (int i = 0; i < alphabet; i++) 
                {
                    if (temp == NULL)
                        return true;
                    if (temp->children[i] == current)
                        temp->children[i] = NULL;
                }
                delete current;
                current = temp;
            }
            else
            {
                return true;
            }
        }
        return true;
    }
    else // the str exist in another word
    {
        current->isEndWord = false;
    }
    return true;
    
 
}

bool Trie::searchWord(string str)
{
    TrieNode* current = root;
    for (int i = 0; i < str.length(); i++)
    {
        int index = str[i] - 'a'; //To know the index of the letter in the arry 
        if (current->children[index] == NULL)
            return false;
        current = current->children[index];
    }
    if (current->isEndWord == true) // the flag is true that mean that the word exist in the trie
        return true;
    return false;
}

int Trie::printAllWordFromPrefix(string str)
{
   
    TrieNode* current = root;
    for (int i = 0; i < str.length(); i++) // Promoting the pointer of the tree to the end of the word of the string (to the last letter)   
    {
        int index = str[i] - 'a'; //To know the index of the letter in the arry 
        if (current->children[index] == NULL)
            return 0;
        current = current->children[index];
    }
    printRecursive(current, str);
     




    return 1;
}

bool Trie::isLeaf(TrieNode* node)
{
   
    for (int i = 0; i < alphabet; i++)
    {
        if (node->children[i] != NULL)
            return false;
    }
    return true;
}

void Trie::printRecursive(TrieNode* node, string str)
{
    if (node->isEndWord == true)
    {
        cout << str << endl;
    }
    for (int i = 0; i < alphabet; i++)
    {
        if (node->children[i] != NULL)
        {
            
            printRecursive(node->children[i], str + (char)(i + 'a'));
        }
    }
       



}
