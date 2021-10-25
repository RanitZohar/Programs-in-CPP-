//Ranit Zohar
//מעבדה 5 שאלה 2
// סדנא ב C
// the program add to more function on the program in question 1

#include <iostream>
#include "List.h"

using namespace std;
List merge(List list1, List list2)//Merge function to merge two lists. The function accepts two sorted lists lst1 and lst2, of type type and returns a new list built from the merge of the two lists in descending order.
{
	int num1;
	int num2;
	List myNew = list1;
	while (!(list2.isEmpty()))
	{
		num2 = list2.firstElement();
		myNew.insert(num2);
		list2.removeFirst();
	}
	return myNew;
}
void makeSet(List& list)//MakeSet function to make a list a group. The function receives a sorted list that does not go down. The function changes the list so that each organ appears only once (after performing the function, there will be no duplicate organs in the list). The list will remain sorted
{  //No need to check input regulations
	
	int num;
	List myList;
	while (!list.isEmpty())
	{
		num = list.firstElement();
		list.removeFirst();
		while ((!list.isEmpty()) && (list.firstElement() == num))
			list.removeFirst();
		myList.insert(num);
	}
	list = myList;
}

int main()
{
	List lst1, lst2, mergedList;
	cout << "enter sorted values for the first list:" << endl;
	cin >> lst1;
	cout << "enter sorted values for the second list:" << endl;
	cin >> lst2;
	mergedList = merge(lst1, lst2);
	cout << "the new merged list: " << mergedList << endl;
	makeSet(mergedList);
	cout << "the new merged set: " << mergedList << endl;

	return 0;

}
