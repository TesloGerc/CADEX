#pragma once

#include <memory>

#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"

class Utils
{
public:
    static std::unique_ptr<Curve> MakeCurve(int type_id) noexcept;

private:
    Utils();
};
