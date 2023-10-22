#include <iostream>
#include <vector>
#include <memory>
#include <random>
#include <numbers>
#include <type_traits>
#include <string>
#include <ctime>

#include <Curves.h>

#ifdef TBB_FOUND
#include "RadiusParallelSummator.h"

#include <tbb/blocked_range.h>
#include <tbb/parallel_reduce.h>
#endif

std::unique_ptr<curves::Curve> MakeRandomCurve(int type_id) noexcept 
{
    std::mt19937 gen(std::random_device{}());
    //Random small numbers for distribution
    std::uniform_real_distribution<double> dist(0.1, 40);

    switch (type_id)
    {
    case curves::CURVE_TYPE::CIRCLE:
        return std::make_unique<curves::Circle>(dist(gen));
        break;
    case curves::CURVE_TYPE::ELLIPSE:
        return std::make_unique<curves::Ellipse>(dist(gen),dist(gen));
        break;
    case curves::CURVE_TYPE::HELIX:
        return std::make_unique<curves::Helix>(dist(gen),dist(gen));
        break;
    default:
        return nullptr;
        break;
    } 
}

std::vector<std::shared_ptr<curves::Curve>> CreateRandomCurves(int count)
{
    std::mt19937 gen(std::random_device{}());

    int CURVETYPE_COUNT = 3;
    std::uniform_int_distribution<std::uint8_t> curve_dist(0, CURVETYPE_COUNT-1);

    std::vector<std::shared_ptr<curves::Curve>> curves(count);

    for(auto& c : curves)
        c = MakeRandomCurve(curve_dist(gen));

    return curves;
}

void Print(const std::vector<std::shared_ptr<curves::Curve>>& curves)
{
    std::cout << "Type\t\tAddress\t\t\tPoint (X, Y, Z)\t\t\t\tFirst Derivative [dxdt, dydt, dzdt]\n";
    for(const auto& c : curves)
    {
        const double t = std::numbers::pi / 4;
        std::cout << c.get()->GetTypeName() << "\t->  " 
                    << c.get() << "  :  "
                    << c.get()->GetPoint(t) << "\t"
                    << c.get()->GetFirstDerivative(t)
                    << "\n";
    }
}

std::vector<std::shared_ptr<curves::Curve>> SelectCircles(const std::vector<std::shared_ptr<curves::Curve>>& curves)
{
    std::vector<std::shared_ptr<curves::Curve>> circles;

    for(const auto& c : curves)
    {
        if(c.get()->GetType() == curves::CURVE_TYPE::CIRCLE)
            circles.push_back(c);
    }
    return circles;
}

void SortByRaius(std::vector<std::shared_ptr<curves::Circle>>& circles)
{
    std::sort(circles.begin(),circles.end(),
                    [](auto a, auto b){return a.get()->GetRadius() < b.get()->GetRadius();});
}

#ifdef TBB_FOUND
double ComputeSumOfRadii(const std::vector<std::shared_ptr<curves::Circle>> &circles)
{
    RadiusParallelSummator summator(circles);
    tbb::parallel_reduce(tbb::blocked_range<size_t>(0, std::size(circles)),
                        summator);
    return summator.getSum();
}
#else
double ComputeSumOfRadii(const std::vector<std::shared_ptr<curves::Circle>> &circles)
{
      return std::accumulate( circles.begin(), circles.end(), 0.,
                                [](double sum, std::shared_ptr<curves::Circle> c)
                                { return sum + c.get()->GetRadius();});
}
#endif

int main()
{
    std::cout << "Enter count of curves:\n";
    int count;
    std::cin >> count;
    //2
    auto curves = CreateRandomCurves(count);
    //3
    std::cout << "Print coordinates of points and derivatives of all curves in the container at t=PI/4\n\n";
    Print(curves);
    std::cout << "\n";
    //4
    std::cout << "Populate a second container that would contain only circles from the first container.\n\n";
    auto selected = SelectCircles(curves);
    Print(selected);
    std::cout << "\n";
    //5
    std::cout << "Sort the second container in the ascending order of circles’ radii.\n\n";
    std::vector<std::shared_ptr<curves::Circle>> circles(selected.size());
    std::transform(selected.begin(),selected.end(),circles.begin(),
                        [](auto s){return std::dynamic_pointer_cast<curves::Circle>(s);});
    std::cout << "Before sorting:\n";
    for(auto c: circles)
        std::cout << c.get() << "\t" << c.get()->GetRadius() << "\n";
    std::cout << "\n";
    std::cout << "After sorting:\n";
    SortByRaius(circles);
    for(auto c: circles)
        std::cout << c.get() << "\t" << c.get()->GetRadius() << "\n";
    std::cout << "\n";
    //6   
    double sum = ComputeSumOfRadii(circles);
    std::cout << "Compute the total sum of radii of all curves in the second container :  " << sum << "\n";
    return 0;
}