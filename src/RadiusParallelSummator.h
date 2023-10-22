#include <vector>
#include <memory>

#include <Curves.h>

#include <tbb/blocked_range.h>

class RadiusParallelSummator
{
public:
  explicit RadiusParallelSummator(const std::vector<std::shared_ptr<Circle>>& circles) : circles(circles), sum(0.) {}

  RadiusParallelSummator(const RadiusParallelSummator &a, tbb::split) : RadiusParallelSummator(a.circles) {}

  double getSum() const noexcept { return sum; }

  void join(const RadiusParallelSummator &a) { sum += a.sum; }

  void operator()(const tbb::blocked_range<size_t> &r) {
    for (size_t i = r.begin(); i != r.end(); ++i) {
      sum += circles[i].get()->GetRadius();
    }
  }
private:
    const std::vector<std::shared_ptr<Circle>>& circles;
    double sum;
};