#include "Rectangle.h"
Rectangle::Rectangle(int side1, int side2) :Polygon(4)
{
	sides[0] = side1;
	sides[1] = side2;
	sides[2] = side1;
	sides[3] = side2;
}
Rectangle::~Rectangle(){}