#include "darts.h"

namespace darts {
  bool in_circle(float squared_distances, float squared_radius) {
    return squared_distances <= squared_radius;
  }

  int score(float x, float y) {
    float squared_distances = (x * x) + (y * y);

    if (in_circle(squared_distances, 1)) {
      return 10;
    } else if (in_circle(squared_distances, 25)) {
      return 5;
    } else if (in_circle(squared_distances, 100)) {
      return 1;
    } else {
      return 0;
    }
  }

} // namespace darts
