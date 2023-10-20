#include "Circle.h"

#include "RadiusException.h"

Circle::Circle(double r)
{
    if(r <= 0)
        throw RadiusException{"Try create circle with negative radius"};

    radius = r;
}

constexpr Point Circle::GetPoint(double t) const noexcept 
{
    // no idea how to error handling
    double x = radius * std::cos(t);
    double y = radius * std::sin(t);
  return Point(x,y);
}

constexpr double Circle::GetFirstDerivative(double t) const noexcept 
{
    //TODO
  return - std::cos(t)/std::sin(t);
}

constexpr CURVE_TYPE Circle::GetType() const noexcept 
{ 
  return CURVE_TYPE::CIRCLE; 
}
