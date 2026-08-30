#include <string>

namespace log_line {
  int get_separation_pos(std::string line) { return line.find(" "); }

  std::string message(std::string line) {
    return line.substr(get_separation_pos(line) + 1, line.size());
  }

  std::string log_level(std::string line) {
    return line.substr(1, get_separation_pos(line) - 3);
  }

  std::string reformat(std::string line) {
    return message(line) + " (" + log_level(line) + ")";
  }
} // namespace log_line
