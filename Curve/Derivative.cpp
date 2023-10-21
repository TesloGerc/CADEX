#include "Derivative.h"

std::ostream& operator<<(std::ostream& os, const Derivative& v) 
{
    os << "[ " << v.dxdt  << "," << v.dydt  << "," << v.dzdt << " ]";
    return os;
}