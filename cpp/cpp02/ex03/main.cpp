#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main(void)
{
    Point const a(-10, 0);
    Point const b(10, 0);
    Point const c(0, 20);
    Point const point(5, 0);

    bsp(a, b, c, point) ? std::cout   << "TRUE" << std::endl : std::cout   << "FLASE" << std::endl;
    return 0;
}