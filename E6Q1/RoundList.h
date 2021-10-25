//Ranit Zohar 
// מעבדה 6 שאלה 1
// סדנא ב C
//RoundList, a linear list in which the last link points to the first link


#pragma once
#include "List.h"
class RoundList : public List
{
public:

	RoundList(); //constructor
	~RoundList(); // destructor


	void add(int val);
	int search(int val);
	void addToEnd(int val);
	void removeFirst();
};
