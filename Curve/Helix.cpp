#include "Helix.h"

#include "RadiusException.h"

Helix::Helix(double r, double step)
{
    if(r <= 0)
        throw RadiusException{"Try create circle with negative radius"};

    radius = r;
    step = step;
}

constexpr Point Helix::GetPoint(double t) const noexcept 
{
    // no idea how to error handling
    double x = radius * std::cos(t);
    double y = radius * std::sin(t);
    double z = step * t;
  return Point(x,y,z);
}

constexpr double Helix::GetFirstDerivative(double t) const noexcept 
{
    //TODO
  return - std::cos(t)/std::sin(t);
}

constexpr CURVE_TYPE Helix::GetType() const noexcept 
{ 
  return CURVE_TYPE::HELIX; 
}