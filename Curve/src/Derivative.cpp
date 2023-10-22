#include "../include/Derivative.h"
#include <iomanip>

namespace curves
{

std::ostream& operator<<(std::ostream& os, const Derivative& v) 
{
    os << "[ " << std::setw(10) << v.dxdt  << ", " << std::setw(10) << v.dydt  << ", " << std::setw(10) << v.dzdt << " ]";
    return os;
}
}