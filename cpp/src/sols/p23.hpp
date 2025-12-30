// https://projecteuler.net/problem=23
// --------------------------------------------------------------------------------------
// Abundant number: a number for which the total sum of
// its proper divisors is greater than itself
// --------------------------------------------------------------------------------------
// Find the sum of all the positive integers which
// cannot be written as the sum of two abundant numbers.

// optimize!

#include <chrono>
#include <cstdint>
#include <iostream>
#include <vector>

#include "include/math-utils.hpp"
#include "include/timer.hpp"

using namespace std::chrono;

inline bool is_abundant(const uint32_t &num) { return sum_divisors(num) > num; }

inline std::vector<uint32_t> find_abundants(const uint32_t &limit) {
  std::vector<uint32_t> abundants;

  // start at 12, the smallest abundant number
  for (uint32_t i = 12; i <= limit; i++) {
    if (is_abundant(i)) {
      abundants.emplace_back(i);
    }
  }

  return abundants;
}

inline void solve_p23() {
  auto start = steady_clock::now();

  constexpr uint32_t limit = 28123;
  uint32_t total_sum = 0;
  uint32_t current_sum = 0;

  std::vector<uint32_t> abundants = find_abundants(limit);

  for (size_t i = 0; i < abundants.size(); i++) {
    for (size_t j = i; j < abundants.size(); j++) {
      current_sum = abundants[i] + abundants[j];

      if (current_sum > limit) {
        break;
      }

      total_sum += i;
    }
  }

  auto end = steady_clock::now();

  std::cout << "Sum of all positive integers that are non-abundant sums: "
            << total_sum << "\n";

  print_time(start, end);
}
