#pragma once

#include <numbers>

#include "Curve.h"

namespace curves
{

    const double PI2 = std::numbers::pi * 2;

    class Helix : public Curve
    {
    public:
        Helix(double r, double s);

        virtual Point GetPoint(double t) const noexcept override;
        virtual Derivative GetFirstDerivative(double t) const noexcept override;
        virtual CURVE_TYPE GetType() const noexcept override;
        constexpr virtual const char* GetTypeName() const noexcept override;
    private:
        double radius;
        double step;
    };

}