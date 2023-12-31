#pragma once

#include "Curve.h"

namespace curves
{

class Circle : public Curve
{
public:

    // Radius should be positive
    explicit Circle(double r);

    constexpr virtual Point GetPoint(double t) const noexcept override;
    constexpr virtual Derivative GetFirstDerivative(double t) const noexcept override;
    constexpr virtual CURVE_TYPE GetType() const noexcept override;
    constexpr virtual const char* GetTypeName() const noexcept override;

    double GetRadius() {return radius;};
private:
    double radius;
};

}