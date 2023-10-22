#include "../include/Point.h"

#include <iomanip>

namespace curves
{

std::ostream& operator<<(std::ostream& os, const Point& p) 
{
    os << "( " << std::setw(10) << p.x  << ", " << std::setw(10) << p.y << ", " << std::setw(10) << p.z << " )";
    return os;
}

}