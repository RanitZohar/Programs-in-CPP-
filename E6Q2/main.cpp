//Ranit Zohar
//מעבדה 6 שאלה 1
// סדנא ב C
//The program receives two-polygon data. The program should check whether the two polygons are equal
//(the number of sides is equal, and the volume is equal)
#include <iostream>
using namespace std;
#include "Triangle.h"
#include "Rectangle.h"
static Polygon buildosh(int size)//The action takes a number of ribs in the polygon, and builds a polygon accordingly by asking values from the variables, and returns the polygon it has constructed
{
	if ((size == 3) || (size == 4))//Construction is different to a triangle and a rectangle
	{
		cout << "enter sides for polygon:" << endl;
		int sidesArr[3];
		for (int i = 0; i < 2; i++)
			cin >> sidesArr[i];
		if (size == 3)
		{
			cin >> sidesArr[2];
			Triangle p1(sidesArr[0], sidesArr[1], sidesArr[2]);
			return p1;
		}
		else
		{
			Rectangle p1(sidesArr[0], sidesArr[1]);
			return p1;
		}
	}
	Polygon p1(size);
	return p1;
}
int main()
{
	int size;
	cout << "enter number of sides for polygon 1:" << endl;
	cin >> size;
	Polygon p1 = buildosh(size);
	cout << "enter number of sides for polygon 2:" << endl;
	cin >> size;
	if (size != p1.getNumSides())
	{
		cout << "not equal" << endl;
		return 0;
	}
	Polygon p2 = buildosh(size);
	if (p1 == p2)
	{
		cout << "equal" << endl;
		return 0;
	}
	cout << "not equal" << endl;
	// system ("pause");
	return 0;
}
/*enter number of sides for polygon 1:
3
enter sides for polygon:
20
10
15
enter number of sides for polygon 2:
3
enter sides for polygon:
11
14
20
equal
Press any key to continue . . .



*/
