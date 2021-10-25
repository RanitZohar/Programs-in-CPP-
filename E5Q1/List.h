//Ranit Zohar ID  208569327
//מעבדה 5 שאלה 1
// סדנא ב C
//the program complete the List class definition that is displayed in the class so that it can handle a list containing sorted organs in ascending order


#pragma once
#include <iostream>
using namespace std;
//----------------------------
// class List
// arbitrary size Lists
// permits insertion and removal
// only from the front of the List
//------------------------------
class List
{
protected:
	//---------------------------
	// inner class link
	// a single element for the linked List
	//---------------------------
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

public:
	List();
	List(const List&);
	~List();


	// operations
	void add(int value);
	int firstElement() const;
	bool search(const int &value) const;
	bool isEmpty() const;
	void removeFirst();
	void clear();
	
	void remove(int key);//The function receives an integer key. If the key value exists in the list, the function deletes it from the list while keeping the list sorted. If the value does not exist, you will send an exception "value not found"
	void insert(int key);//The function receives an integer key and puts it in the appropriate place in the sorted list.
	List operator=(List MyList);
	friend ostream& operator<<(ostream& os, const List & num);
	friend istream& operator>>(istream& is, List  & num);


protected:
	// data field
	Link* head;//end of class Link


};