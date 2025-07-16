#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    float big_triangle;
    float pab_triangle;
    float pac_triangle;
    float pbc_triangle;

    big_triangle =  std::fabs(((a.getXpoint() * (b.getYpoint() - c.getYpoint())) + \
                    (b.getXpoint() * (c.getYpoint() - a.getYpoint())) + \
                    c.getXpoint() * (a.getYpoint() - b.getYpoint()))) / 2;
    std::cout   << "big triangle area: " << big_triangle << std::endl;
    pab_triangle =  std::fabs(((point.getXpoint() * (a.getYpoint() - b.getYpoint())) + \
                    (a.getXpoint() * (b.getYpoint() - point.getYpoint())) + \
                    b.getXpoint() * (point.getYpoint() - a.getYpoint()))) / 2;
    std::cout   << "pab triangle area: " << pab_triangle << std::endl;
    pac_triangle =  std::fabs(((point.getXpoint() * (a.getYpoint() - c.getYpoint())) + \
                    (a.getXpoint() * (c.getYpoint() - point.getYpoint())) + \
                    c.getXpoint() * (point.getYpoint() - a.getYpoint()))) / 2;
    std::cout   << "pac triangle area: " << pac_triangle << std::endl;
    pbc_triangle =  std::fabs(((point.getXpoint() * (b.getYpoint() - c.getYpoint())) + \
                    (b.getXpoint() * (c.getYpoint() - point.getYpoint())) + \
                    c.getXpoint() * (point.getYpoint() - b.getYpoint()))) / 2;
    std::cout   << "pbc triangle area: " << pbc_triangle << std::endl;
    std::cout   << "three p triangle area: " << pab_triangle + pac_triangle + pbc_triangle << std::endl;
    return (pab_triangle && pac_triangle && pbc_triangle && big_triangle >= pab_triangle + pac_triangle + pbc_triangle ? true : false);
}