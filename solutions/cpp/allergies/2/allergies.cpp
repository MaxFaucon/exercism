#include "allergies.h"
#include <string>
#include <unordered_map>
#include <unordered_set>

namespace allergies {
  const std::unordered_map<std::string, int> allergens = {
      {"eggs", 1},         {"peanuts", 2},   {"shellfish", 4},
      {"strawberries", 8}, {"tomatoes", 16}, {"chocolate", 32},
      {"pollen", 64},      {"cats", 128}};

  allergy_test::allergy_test(int allergy_score) {
    for (const auto &[name, score] : allergens) {
      if (allergy_score & score) {
        m_allergies.insert(name);
      }
    }
  }

  bool allergy_test::is_allergic_to(const std::string &allergen_name) const {
    return m_allergies.count(allergen_name) > 0;
  }

  const std::unordered_set<std::string> &allergy_test::get_allergies() const {
    return m_allergies;
  }
} // namespace allergies
