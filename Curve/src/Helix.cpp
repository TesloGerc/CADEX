#include "../include/Helix.h"

#include "../include/RadiusException.h"

namespace curves
{

Point Helix::GetPoint(double t) const noexcept 
{
    Point circlePoint = circle.GetPoint(t);
    double z = step * (t/curves::PI2);
  return Point(circlePoint.GetX(),circlePoint.GetY(),z);
}

Derivative Helix::GetFirstDerivative(double t) const noexcept 
{
    Derivative circleDer = circle.GetPoint(t);
    double dzdt = step * (t/curves::PI2);
    return Derivative(circleDer.GetX(),circleDer.GetY(),dzdt);
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