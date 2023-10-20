#include <iostream>
#include <vector>
#include <memory>
#include <random>
#include <numbers>
#include <type_traits>
#include <string>
#include <ctime>

#include "Curve/Circle.h"
#include "Curve/Ellipse.h"
#include "Curve/Helix.h"



std::unique_ptr<Curve> CreateRandomCurve()
{
    int type = std::rand()%3;
    switch (type)
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

std::string PrintCurveType(CURVE_TYPE type)
{
    switch (type)
    {
    case CURVE_TYPE::CIRCLE:
        return "Circle";
        break;
    case CURVE_TYPE::ELLIPSE:
        return "Ellipse";
        break;
    case CURVE_TYPE::HELIX:
        return "Helix";
        break;
    default:
        return nullptr;
        break;
    }
}

std::vector<std::shared_ptr<Curve>> CreateRandomCurves(int count)
{
    std::vector<std::shared_ptr<Curve>> curves(count);

    for(auto& c : curves)
        c = CreateRandomCurve();

    return curves;
}

void Print(const std::vector<std::shared_ptr<Curve>>& curves)
{
    for(const auto& c : curves)
    {
        const double t = std::numbers::pi / 4;
        std::cout << PrintCurveType(c.get()->GetType()) << "\t->\t" 
                    << c.get() << "\t:\t"
                    << c.get()->GetPoint(t) << "\t"
                    << c.get()->GetFirstDerivative(t)
                    << "\n";
    }
}

std::vector<std::shared_ptr<Curve>> SelectCircles(const std::vector<std::shared_ptr<Curve>>& curves)
{
    std::vector<std::shared_ptr<Curve>> circles;
    for(const auto& c : curves)
    {
        if(c.get()->GetType() == CURVE_TYPE::CIRCLE)
        {
            circles.push_back(c);
        }
    }
    return circles;
}

int main()
{
    std::srand(std::time(NULL));
    int count = 10;
    //2
    auto curves = CreateRandomCurves(count);
    //3
    Print(curves);
    std::cout << "\n";
    //4
    auto selected = SelectCircles(curves);
    Print(selected);
    std::cout << "\n";
    //5
    std::vector<std::shared_ptr<Circle>> circles(selected.size());
    std::transform(selected.begin(),selected.end(),circles.begin(),
                        [](auto s){return std::dynamic_pointer_cast<Circle>(s);});
    for(auto c: circles)
        std::cout << c.get()->GetRadius() << "\n";
    std::cout << "\n";
    std::sort(circles.begin(),circles.end(),
                    [](auto a, auto b){return a.get()->GetRadius() < b.get()->GetRadius();});
    for(auto c: circles)
        std::cout << c.get()->GetRadius() << "\n";
    std::cout << "\n";
    //6
    double sum = std::accumulate(circles.begin(),circles.end(),0.0,
                                    [](double a,auto b){return a + b.get()->GetRadius();});
    std::cout << sum << "\n";
    return 0;
}