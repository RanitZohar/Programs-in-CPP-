#pragma once
#include <iostream>
using namespace std;
//-------------------------
// class List
// arbitrary size Lists
// permits insertion and removal
// only from the front of the List
//--------------------------
class List
{
protected:
	//-----------------------
	// inner class link
	// a single element for the linked List
	//-----------------------
	class Link
	{
	public:
		// constructor
		Link(int linkValue, Link * nextPtr);
		Link(const Link &);
		// data areas
		int value;
		Link * next;
	};
protected:
	// data field
	Link* head;
public:
	//constructors
	List();
	List(const List&);
	~List();
	
	// operations
	void add(int value);
	int firstElement() const;
	bool isEmpty() const;
	void removeFirst();
	void clear();
	
	List operator=(List MyList);
};