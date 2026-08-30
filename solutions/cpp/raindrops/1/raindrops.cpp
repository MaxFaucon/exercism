#include "raindrops.h"
#include <string>

namespace raindrops {

  std::string convert(int number) {
    std::string raindrop_sound = "";

    if (number % 3 == 0)
      raindrop_sound += "Pling";

    if (number % 5 == 0)
      raindrop_sound += "Plang";

    if (number % 7 == 0)
      raindrop_sound += "Plong";

    return raindrop_sound == "" ? std::to_string(number) : raindrop_sound;
  }

} // namespace raindrops
