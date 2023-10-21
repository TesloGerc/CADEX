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

constexpr Derivative Circle::GetFirstDerivative(double t) const noexcept 
{
  double dxdt = - radius * std::sin(t);
  double dydt = radius * std::cos(t);
  double dzdt = 0;

  return Derivative(dxdt,dydt,dzdt);
}

constexpr CURVE_TYPE Circle::GetType() const noexcept 
{ 
  return CURVE_TYPE::CIRCLE; 
}

constexpr const char* Circle::GetTypeName() const noexcept 
{
  return "Circle";
}
