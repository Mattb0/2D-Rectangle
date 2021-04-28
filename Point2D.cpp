#include <iostream>
#include "Point2D.h"
#include "2DRectangle.h"

Point2D::Point2D()
{
	_x = 0;
	_y = 0;
	std::cout << "\n------ Point2D class initialized ------\npointing at: " << getX() << ", " << getX() << "\n\n\n";
}

Point2D::Point2D(float x, float y)
{
	_x = x;
	_y = y;
	std::cout << "\n------ Point2D class initialized ------\npointing at: " << getX() << ", " << getX() << "\n\n\n";
}