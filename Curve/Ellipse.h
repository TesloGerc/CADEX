#pragma once

#include "Curve.h"

class Ellipse : public Curve
{
public:

    // Radius should be positive
    Ellipse(double xr,double yr);

    constexpr virtual Point GetPoint(double t) const noexcept override;
    constexpr virtual double GetFirstDerivative(double t) const noexcept override;
    constexpr virtual CURVE_TYPE GetType() const noexcept override;
private:
    double xRadius;
    double yRadius;
};