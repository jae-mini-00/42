#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private :
        Fixed const x;
        Fixed const y;
    public :
        Point();
        Point(float x_point, float y_point);
        Point(const Point& other);
        Point& operator=(const Point& other);
        ~Point();
        float getXpoint() const;
        float getYpoint() const;
};

#endif