#pragma once

#include "Curve.h"

class Circle : public Curve
{
public:

    // Radius should be positive
    Circle(double r);

    constexpr virtual Point GetPoint(double t) const noexcept override;
    constexpr virtual Derivative GetFirstDerivative(double t) const noexcept override;
    constexpr virtual CURVE_TYPE GetType() const noexcept override;

    double GetRadius() {return radius;};
    constexpr virtual const char* GetTypeName() const noexcept;
private:
    double radius;
};