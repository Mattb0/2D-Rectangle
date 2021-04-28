#pragma once
#include <fstream>
#include <iostream>
#include <string>

class Point2D
{
private:
	float _x = 0;
	float _y = 0;
public:
	Point2D();
	Point2D(float x, float y);

	float getX()
	{
		return _x;
	}

	float getY()
	{
		return _y;
	}
};