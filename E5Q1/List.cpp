//Ranit Zohar ID  208569327
//מעבדה 5 שאלה 1
// סדנא ב C
//the program complete the List class definition that is displayed in the class so that it can handle a list containing sorted organs in ascending order


#include "List.h"
#include <iostream>
using namespace std;
//------------------------------
// class Link implementation
//------------------------------
List::Link::Link(int val, Link* nxt) :value(val), next(nxt) {}
List::Link::Link(const Link& source) : value(source.value), next(source.next) {}
//------------------------------
// class List implementation
//------------------------------

List::List() : head(NULL)
{
	// no further initialization
}
List::List(const List &l)
{
	Link *src, *trg;
	if (l.head == NULL)
		head = NULL;
	else
	{
		head = new Link((l.head)->value, NULL);
		src = l.head;
		trg = head;
		while (src->next != NULL)
		{
			trg->next = new Link
			((src->next)->value, NULL);
			src = src->next;
			trg = trg->next;
		}
	}
}
List::~List()
{
	clear();
}
void List::clear()
{
	// empty all elements from the List
	Link* next;
	for (Link * p = head; p != NULL; p = next)
	{
		// delete the element pointed to by p
		next = p->next;
		p->next = NULL;
		delete p;
	}
	// mark that the List contains no elements
	head = NULL;
}
bool List::isEmpty() const
{
	// test to see if the List is empty
	// List is empty if the pointer to the head
	// Link is null

	return head == NULL;
}
void List::add(int val)
{
	//Add a new value to the front of a Linked List
	head = new Link(val, head);
	if (head == NULL)
		throw "failed in memory allocation";
}
int List::firstElement() const
{
	// return first value in List
	if (isEmpty())
		throw "the List is empty, no first Element";
	return head->value;
}
bool List::search(const int &val) const
{
	// loop to test each element
	for (Link* p = head; p != NULL; p = p->next)
		if (val == p->value)
			return true;
	// not found
	return false;
}
void List::removeFirst()
{
	// make sure there is a first element
	if (isEmpty())
		throw "the List is empty, no Elements to remove";
	// save pointer to the removed node
	Link* p = head;
	// reassign the first node
	head = p->next;
	p->next = NULL;
	// recover memory used by the first element
	delete p;
}


void List::insert(int key)
{
	Link * p = head;
	if (head == NULL || head->value > key)
	{
		add(key);
		return;
	}
	while (p->next != NULL && p->next->value < key)
		p = p->next;
	p->next = new Link(key, p->next);
}
void List::remove(int key)
{
	if (key == head->value)
	{
		removeFirst();
		return;
	}
	for (Link* p = head; p->next != NULL; p = p->next)
		if (key == p->next->value)
		{
			Link* k = p->next;
			p->next = k->next;
			k->next = NULL;
			delete k;
			return;
		}
	// not found
	throw "value not found";
}
istream& operator>>(istream& is, List  & num)
{
	List::Link* l = num.head;
	int val;
	is >> val;
	num.add(val);
	l = num.head;
	is >> val;
	while (val > l->value)
	{
		l->next = new List::Link(val, NULL);
		l = l->next;
		is >> val;
	}
	return is;
}
ostream& operator<<(ostream& os, const List  & num)
{
	List::Link* l = num.head;
	while (l)
	{
		os << l->value << ' ';
		l = l->next;
	}
	return os;
}
List List::operator=(List MyList)
{
	List l;
	Link *src, *trg;
	if (l.head == NULL)
		head = NULL;
	else
	{
		head = new Link((l.head)->value, NULL);
		src = l.head;
		trg = head;
		while (src->next != NULL)
		{
			trg->next = new Link
			((src->next)->value, NULL);
			src = src->next;
			trg = trg->next;
		}
	}
	return l;
}

