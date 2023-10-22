#include "../include/Circle.h"

#include "../include/RadiusException.h"

namespace curves
{

CURVE_TYPE Circle::GetType() const noexcept 
{ 
  return CURVE_TYPE::CIRCLE; 
}

constexpr const char* Circle::GetTypeName() const noexcept 
{
  return "Circle";
}

}
