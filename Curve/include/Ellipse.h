#pragma once

#include "Curve.h"

namespace curves
{

class Ellipse : public Curve
{
public:

    // Radius should be positive
    Ellipse(double xr,double yr);

    virtual Point GetPoint(double t) const noexcept override;
    virtual Derivative GetFirstDerivative(double t) const noexcept override;
    virtual CURVE_TYPE GetType() const noexcept override;
    constexpr virtual const char* GetTypeName() const noexcept override;

    double GetXRadius() {return xRadius;};
    double GetYRadius() {return yRadius;};
private:
    double xRadius;
    double yRadius;
};

}