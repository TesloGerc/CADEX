#pragma once
#include <iostream>

class Derivative
{
public:
    constexpr Derivative(double dxdt, double dydt, double dzdt = 0) : dxdt(dxdt), dydt(dydt), dzdt(dzdt){};

    constexpr double GetDxDt() const noexcept {return dxdt;};
    constexpr double GetDyDt() const noexcept {return dydt;};
    constexpr double GetDzDt() const noexcept {return dzdt;};

    friend std::ostream& operator<<(std::ostream& os, const Derivative& v);

private:
    double dxdt,dydt,dzdt;    
};