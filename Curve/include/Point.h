#pragma once

#include <iostream>

class Point
{
public:
    constexpr Point() : x(0.0), y(0.0), z(0.0){};
    constexpr Point(double x, double y, double z = 0) : x(x), y(y), z(z){};

    constexpr double GetX() const noexcept {return x;};
    constexpr double GetY() const noexcept {return y;};
    constexpr double GetZ() const noexcept {return z;};

    friend std::ostream& operator<<(std::ostream& os, const Point& p);

private:
    double x,y,z;
};