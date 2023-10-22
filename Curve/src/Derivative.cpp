#include "../include/Derivative.h"

std::ostream& operator<<(std::ostream& os, const Derivative& v) 
{
    os << "[ " << v.dxdt  << ",\t" << v.dydt  << ",\t" << v.dzdt << " ]";
    return os;
}