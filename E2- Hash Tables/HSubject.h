#pragma once
#include "Item.h"
#include "HashTable.h"
class HSubject : public HashTable<string, list<string> >
{
public:
	HSubject(int size) :HashTable(size) {};
	void printS(string subject); //print all titles of the subject
	void addSubjectAndTitle(string subject, string title); //Add a subject and a title
	void printN(string subject, int n); //print N first appearances of a subect
	void startNewTable(); //initialization hash table
	void print();  //print all non-empty entries 
	int h1(string title);
	int h2(string title);
};

