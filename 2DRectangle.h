#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "Point2D.h"

class Rectangle2D
{
	public:
		Rectangle2D(const float x, const float y, const float len, const float h);
		Rectangle2D(const Rectangle2D& obj);
		Rectangle2D& operator=(const Rectangle2D& rectObj);
		float GetBounds();	
		bool compareCords(Point2D& pointObj);
		bool compareCords(Rectangle2D& rectObj);

		float getLength()
		{
			return length;
		}

		float getHeight()
		{
			return height;
		}

		float getXPos()
		{
			return posX;
		}

		float getYPos()
		{
			return posY;
		}

	private: 
		float posX;
		float posY;
		float length;
		float height;
};
