//Ranit Zohar 
//מעבדה 5 שאלה 1
// סדנא ב C
//the program complete the List class definition that is displayed in the class so that it can handle a list containing sorted organs in ascending order



#include <iostream>
#include "List.h"
using namespace std;
int main()
{
	List lst;
	int choice, val;
	cout << "enter the list values\n";
	cin >> lst;
	cout << "choose 0-2\n";
	cin >> choice;
	while (choice)
	{
		switch (choice)
		{
		case 1:cout << "enter a value to insert\n";
			cin >> val;
			lst.insert(val);
			break;
		case 2:cout << "enter a value to remove\n";
			cin >> val;
			try {
				lst.remove(val);
			}
			catch (char * msg)
			{
				cout << msg << endl;
			}
			break;
		default:cout << "ERROR\n";
		}
		cout << lst << endl;
		cout << "choose 0-2\n";
		cin >> choice;
	}
	return 0;
}
