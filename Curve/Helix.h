#pragma once

#include "Curve.h"

class Helix : public Curve
{
public:
    Helix(double r, double step);

    constexpr virtual Point GetPoint(double t) const noexcept override;
    constexpr virtual double GetFirstDerivative(double t) const noexcept override;
    constexpr virtual CURVE_TYPE GetType() const noexcept override;
private:
    double radius;
    double step;
};