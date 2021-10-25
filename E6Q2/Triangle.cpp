#include "Triangle.h"
Triangle::Triangle(int side1, int side2, int side3) :Polygon(3)
{
	sides[0] = side1;
	sides[1] = side2;
	sides[2] = side3;
}
Triangle::~Triangle(){}