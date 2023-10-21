#include "Point.h"

std::ostream& operator<<(std::ostream& os, const Point& p) 
{
    os << "( " << p.x  << ",\t" << p.y << ",\t" << p.z << " )";
    return os;
}