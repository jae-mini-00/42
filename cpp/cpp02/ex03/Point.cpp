#include "Point.hpp"

Point::Point() : x(0), y(0)
{
    ;
}

Point::Point(float x_point, float y_point) : x(x_point), y(y_point)
{
    ;
}

Point::Point(const Point& other) : x(other.x), y(other.y)
{
    ;
}

Point& Point::operator=(const Point& other)
{
    if (this != &other)
        std::cout   << "Cannot assign to const member" << std::endl;
    return (*this);
}

Point::~Point()
{
    ;
}

float Point::getXpoint() const
{
    return (x.toFloat());
}
float Point::getYpoint() const
{
    return (y.toFloat());
}