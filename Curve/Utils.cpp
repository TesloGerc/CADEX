#include "Utils.h"

std::unique_ptr<Curve> Utils::MakeCurve(int type_id) noexcept 
{
    switch (type_id)
    {
    case CURVE_TYPE::CIRCLE:
        return std::make_unique<Circle>(rand());
        break;
    case CURVE_TYPE::ELLIPSE:
        return std::make_unique<Ellipse>(rand(),rand());
        break;
    case CURVE_TYPE::HELIX:
        return std::make_unique<Helix>(rand(),rand());
        break;
    default:
        return nullptr;
        break;
    } 
}