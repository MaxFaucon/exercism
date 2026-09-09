#include "allergies.h"
#include <string>
#include <unordered_map>
#include <unordered_set>

namespace allergies {
  const std::unordered_map<std::string, int> allergens = {
      {"eggs", 1},         {"peanuts", 2},   {"shellfish", 4},
      {"strawberries", 8}, {"tomatoes", 16}, {"chocolate", 32},
      {"pollen", 64},      {"cats", 128}};

  allergy_test::allergy_test(int allergy_score) : m_score{allergy_score} {}

  bool allergy_test::is_allergic_to(const std::string &allergen_name) const {
    auto allergen = allergens.find(allergen_name);

    if (allergen == allergens.end()) {
      return false;
    }

    return has_allergen(allergen->second);
  }

  std::unordered_set<std::string> allergy_test::get_allergies() const {
    std::unordered_set<std::string> allergies;

    for (const auto &[name, score] : allergens) {
      if (has_allergen(score)) {
        allergies.insert(name);
      }
    }

    return allergies;
  }

  bool allergy_test::has_allergen(const int score) const {
    return (m_score & score) != 0;
  }

} // namespace allergies
