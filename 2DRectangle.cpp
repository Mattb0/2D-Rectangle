#include <iostream>
#include "Point2D.h"
#include "2DRectangle.h"

// Default constructor
Rectangle2D::Rectangle2D(const float x, const float y, const float len, const float h)
{
    length = len;
    height = h;

    Rectangle2D::posX = x;
    Rectangle2D::posY = y;

    std::cout << "------ Rectangle2D constructed ------\n";
    std::cout << "                     [X]   [Y]" << "\n";
    std::cout << "from:                 " << x << "     " << y << "\n";
    std::cout << "to:                   " << x + Rectangle2D::getLength() << "     " << y + Rectangle2D::getHeight() << "\n\n";
}

// Copy constructor
Rectangle2D::Rectangle2D(const Rectangle2D& obj)
{
    Rectangle2D::length = obj.length;
    Rectangle2D::height = obj.height;

    Rectangle2D::posX = obj.posX;
    Rectangle2D::posY = obj.posY;
}


float Rectangle2D::GetBounds()
{
    return 0;
}

// Checks whether or not two axis-aligned Rectangles intersect
bool Rectangle2D::compareCords(Rectangle2D& RectObj)
{
    float minX = Rectangle2D::getXPos();
    float minY = Rectangle2D::getYPos();
    float maxX = minX + Rectangle2D::getLength();
    float maxY = minY + Rectangle2D::getHeight();

    float obj_minX = RectObj.getXPos();
    float obj_minY = RectObj.getYPos();
    float obj_maxX = obj_minX + RectObj.getLength();
    float obj_maxY = obj_minX + RectObj.getHeight();


    if ( (obj_minX >= minX && obj_minX <= maxX) && (obj_minY >= minY && obj_minY <= maxY) && 
        (obj_maxX >= minX && obj_maxX <= maxX ) && (obj_maxY >= minY && obj_maxY <= maxY) )
    {
        std::cout << "1: Two axis-aligned Rectangles intersect [TRUE]\n";
        return true;
    }
    else 
    {
        std::cout << "1: Two axis-aligned Rectangles intersect [FALSE]\n";
        return false;
    }
}

// checks whether or not a 2D point is contained in an axis-aligned Rectangle
bool Rectangle2D::compareCords(Point2D& pointObj)
{
    float minX = Rectangle2D::getXPos();
    float minY = Rectangle2D::getYPos();
    float maxX = minY + Rectangle2D::getLength();
    float maxY = minX + Rectangle2D::getHeight();

    std::cout << "Size X: " << minX << " to  " << minX + maxX << "\n";
    std::cout << "Size Y: " << minY << " to  " << minY + maxY << "\n";



    if ( (pointObj.getX() >= minX && pointObj.getX() <= maxX) && (pointObj.getY() >= minY && pointObj.getY() <= maxY) )
    {
        std::cout << "2: 2D Point is contained with an axis-aligned Rectangle [TRUE]\n";
        return true;
    }
    else 
    {
        std::cout << "2:  2D Point is contained with an axis-aligned Rectangle [FALSE]\n";
        return false;
    }
}

Rectangle2D& Rectangle2D::operator=(const Rectangle2D& rectObj)
{
    if (this == &rectObj)
    {
        Rectangle2D::length = rectObj.length;
        Rectangle2D::height = rectObj.height;
        Rectangle2D::posX = rectObj.posX;
        Rectangle2D::posY = rectObj.posY;
    }
    return *this;
}

int main()
{
    Rectangle2D Rect1(0, 5, 2, 10);
    Rectangle2D Rect2(2, 5, 1, 7);  
    Rectangle2D Rect3(1, 3, 3, 9);
    Rectangle2D Rect4(0, 5, 2, 5);
    Point2D PointObj(4, 9);

    std::cout << "\n---Testing Rect 1---\n";
    Rect1.compareCords(PointObj);
    std::cout << "\n---Testing Rect 2---\n";  
    Rect2.compareCords(PointObj);
    Rect2.compareCords(Rect1);
    std::cout << "\n---Testing Rect 3---\n";
    Rect3.compareCords(PointObj);
    Rect3.compareCords(Rect1);
    std::cout << "\n---Testing Rect 4---\n";
    Rect4.compareCords(PointObj);
    Rect4.compareCords(Rect1);

     std::cout << "\n\n---Copy constructor---\nRect1: " << Rect1.getHeight() << " " << Rect1.getLength();
     std::cout << "\nCreating copyRect and copying Rect1...";
     Rectangle2D copyRect(Rect1);
     std::cout << "\nCopyRect: " << copyRect.getHeight() << " " << copyRect.getLength();

    std::cout << "\n\n---Assignment Operator---\nRect2: " << Rect2.getHeight() << " " << Rect2.getLength();
    std::cout << "\nCreating assignRect ( assignRect = Rect2 )";
    Rectangle2D assignRect(Rect2);
    std::cout << "\nassignRect: " << assignRect.getHeight() << " " << assignRect.getLength();

    std::cout << "\n\n\n";
}
