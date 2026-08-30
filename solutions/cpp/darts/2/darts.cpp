#include "darts.h"
#include <map>

namespace darts {
  int score(double x, double y) {
    std::map<double, int> radius_scores = {{1, 10}, {25, 5}, {100, 1}};
    auto it = radius_scores.lower_bound((x * x) + (y * y));

    return it == radius_scores.end() ? 0 : it->second;
  }

} // namespace darts
