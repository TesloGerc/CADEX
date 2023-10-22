#pragma once

#include "Ellipse.h"

namespace curves
{

class Circle : public Ellipse
{
public:

    // Radius should be positive
    explicit Circle(double r) : Ellipse(r,r){};

    virtual CURVE_TYPE GetType() const noexcept override;
    constexpr virtual const char* GetTypeName() const noexcept override;

    double GetRadius() {return GetXRadius();};
};

}