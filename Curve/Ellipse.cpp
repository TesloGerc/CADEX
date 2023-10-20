#include "Ellipse.h"

#include "RadiusException.h"

Ellipse::Ellipse(double rx, double ry)
{
    if(rx <= 0 || ry <= 0)
        throw RadiusException{"Try create circle with negative radii"};

    xRadius = rx;
    yRadius = ry;
}

constexpr Point Ellipse::GetPoint(double t) const noexcept 
{
    // no idea how to error handling
    double x = xRadius * std::cos(t);
    double y = yRadius * std::sin(t);
  return Point(x,y);
}

constexpr double Ellipse::GetFirstDerivative(double t) const noexcept 
{
    //TODO
  return - (yRadius / xRadius) * std::cos(t)/std::sin(t);
}

constexpr CURVE_TYPE Ellipse::GetType() const noexcept 
{ 
  return CURVE_TYPE::ELLIPSE; 
}