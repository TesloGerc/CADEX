#pragma once

#include "Curve.h"

class Helix : public Curve
{
public:
    Helix(double r, double step);

    constexpr virtual Point GetPoint(double t) const noexcept override;
    constexpr virtual Derivative GetFirstDerivative(double t) const noexcept override;
    constexpr virtual CURVE_TYPE GetType() const noexcept override;
    constexpr virtual const char* GetTypeName() const noexcept;
private:
    double radius;
    double step;
};