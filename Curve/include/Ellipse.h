#pragma once

#include "Curve.h"

namespace curves
{

class Ellipse : public Curve
{
public:

    // Radius should be positive
    Ellipse(double xr,double yr);

    constexpr virtual Point GetPoint(double t) const noexcept override;
    constexpr virtual Derivative GetFirstDerivative(double t) const noexcept override;
    constexpr virtual CURVE_TYPE GetType() const noexcept override;
    constexpr virtual const char* GetTypeName() const noexcept override;
private:
    double xRadius;
    double yRadius;
};

}