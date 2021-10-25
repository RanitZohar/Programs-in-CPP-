#pragma once
class Polygon
{
protected:
	int numSides;
	int* sides;
public:
	Polygon(int MyNumSides);  //constructor
	Polygon(const Polygon & myPolygon);   //copy constructor
	~Polygon();  //destructor

	int* getSides()const;
	int getNumSides()const;
	int scope()const;
	bool operator==(Polygon & myPolygon)const;
	
	
};