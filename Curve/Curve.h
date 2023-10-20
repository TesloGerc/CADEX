#pragma once

#include <cmath>

#include "Point.h"

enum CURVE_TYPE
{
    CIRCLE = 0,
    ELLIPSE,
    HELIX
};

class Curve
{
public:
    constexpr virtual Point GetPoint(double t) const noexcept = 0;
    constexpr virtual double GetFirstDerivative(double t) const noexcept = 0;

    constexpr virtual CURVE_TYPE GetType() const noexcept = 0;
};