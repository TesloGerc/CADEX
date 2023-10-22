#include "../include/Helix.h"

#include "../include/RadiusException.h"

namespace curves
{

Helix::Helix(double r, double s)
{
    if(r <= 0)
        throw RadiusException{"Try create circle with negative radius"};

    radius = r;
    step = s;
}

Point Helix::GetPoint(double t) const noexcept 
{
    // no idea how to error handling
    double x = radius * std::cos(t);
    double y = radius * std::sin(t);
    double z = step * (t/curves::PI2);
  return Point(x,y,z);
}

Derivative Helix::GetFirstDerivative(double t) const noexcept 
{
  double dxdt = - radius * std::sin(t);
  double dydt = radius * std::cos(t);
  double dzdt = step/curves::PI2;

  return Derivative(dxdt,dydt,dzdt);
}

CURVE_TYPE Helix::GetType() const noexcept 
{ 
  return CURVE_TYPE::HELIX; 
}

constexpr const char* Helix::GetTypeName() const noexcept
{
  return "Helix";
}

}