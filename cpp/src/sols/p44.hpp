// https://projecteuler.net/problem=44
// --------------------------------------------------------------------------------------
// P-n = (n * (3n - 1)) / 2
// --------------------------------------------------------------------------------------
// Find the pair of pentagonal numbers, j and k, for which:
//   - their sum and difference are both pentagonal
//   - d = |j - k| is minimized
// --------------------------------------------------------------------------------------
// What is the value of d?

// optimize!

#include <chrono>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>

#include "include/math-utils.hpp"
#include "include/stopwatch.hpp"

using namespace std::chrono;

inline std::vector<uint64_t> find_pentagonals(const uint64_t &n) {
  std::vector<uint64_t> pentagonals;

  // use formula to calculate the first n pentagonal numbers
  for (uint64_t i = 1; i <= n; i++) {
    pentagonals.emplace_back((i * (3 * i - 1)) / 2);
  }

  return pentagonals;
}

inline void solve_p44() {
  auto start = steady_clock::now();

  constexpr uint64_t search_limit = 5e3;
  uint64_t diff = 0;
  uint64_t min_d = UINT64_MAX;

  std::vector<uint64_t> pents = find_pentagonals(search_limit);

  // only check pairs where j > k
  for (size_t j = 1; j < pents.size(); j++) {
    for (size_t k = 0; k < j; k++) {
      diff = std::abs(static_cast<int64_t>(pents[j] - pents[k]));

      if (diff >= min_d) {
        // don't bother checking pentagonality for big diff
        continue;
      }

      if (is_pentagonal(pents[j] + pents[k]) && is_pentagonal(diff)) {
        min_d = diff;
      }
    }
  }

  auto end = steady_clock::now();

  std::cout << "Minimum difference produced by extra-pentagonal numbers: "
            << min_d << "\n";

  stopwatch(start, end);
}
