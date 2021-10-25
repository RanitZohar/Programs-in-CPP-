#include "Polygon.h"
#include <iostream>
using namespace std;
Polygon::Polygon(int myNumSides)
{
	sides = new int[myNumSides];
	if ((myNumSides != 3) && (myNumSides != 4))
	{
		cout << "enter sides for polygon:" << endl;
		for (int i = 0; i < myNumSides; i++)
			cin >> sides[i];
	}
	numSides = myNumSides;
}
Polygon::Polygon(const Polygon & myPolygon)
{
	numSides = myPolygon.numSides;
	sides = new int[numSides];
	for (int i = 0; i < numSides; i++)
		sides[i] = myPolygon.sides[i];
}
Polygon::~Polygon()
{
	delete[] sides;
}

int* Polygon::getSides()const
{
	return sides;
}
int Polygon::getNumSides()const
{
	return numSides;
}

int Polygon::scope()const
{
	int sum = 0;
	for (int i = 0; i < numSides; i++)
		sum += sides[i];
	return sum;
}
bool Polygon:: operator==(Polygon & myPolygon)const
{
	if (this->numSides != myPolygon.numSides)
		return false;
	return (this->scope() == myPolygon.scope());

}
