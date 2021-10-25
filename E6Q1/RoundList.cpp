//Ranit Zohar 
// מעבדה 6 שאלה 1
// סדנא ב C
//RoundList, a linear list in which the last link points to the first link

#include "RoundList.h"


RoundList::RoundList() {}
RoundList::~RoundList() {}

void RoundList::add(int val)
{
	if (head == NULL)
	{
		head = new Link(val, NULL);
		head->next = head;
		return;
	}
	//Add a new value to the front of a Linked List
	Link* p = head;
	while (p->next != head)
		p = p->next;
	head = new Link(val, head);
	if (head == NULL)
		throw "failed in memory allocation";
	p->next = head;
}
int RoundList::search(int val) //The program receives as a non-negative integer parameter,n.The method returns the value of the organ instead of n in the circular list.
{
	if (val < 0)
		throw "ERROR";
	Link* p = head;
	if (p == NULL)
		return -1;
	for (int i = 0; i < val; i++)
		p = p->next;
	return p->value;
}
void RoundList::addToEnd(int val)  //The program receives as a parameter Integer val, adding a link at the end of the list with the value v
{
	if (head == NULL)
	{
		head = new Link(val, NULL);
		head->next = head;
		return;
	}
	Link* p = head;
	while (p->next != head)
		p = p->next;
	p->next = new Link(val, head);
}
void RoundList::removeFirst()
{
	// make sure there is a first element
	if (isEmpty())
		throw "the List is empty, no Elements to remove";
	Link* h = head;
	while (h->next != head)
		h = h->next;
	// save pointer to the removed node
	Link* p = head;
	// reassign the first node
	if (p->next == head)
	{
		head = NULL;
		return;
	}
	head = p->next;
	p->next = NULL;
	// recover memory used by the first element
	delete p;
	h->next = head;
}

