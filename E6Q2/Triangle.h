#pragma once
#include "Polygon.h"
class Triangle :public Polygon
{
public:
	Triangle(int side1, int side2, int side3);  //constructor
	~Triangle();  //destructor
};

