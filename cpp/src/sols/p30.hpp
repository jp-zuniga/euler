// https://projecteuler.net/problem=30
// -------------------------------------------------------------------------------------
// Find the sum of all numbers that can be written as
// the sum of the fifth power of their digits.

// optimize!

#include <chrono>
#include <cmath>
#include <cstdint>
#include <iostream>

#include "include/stopwatch.hpp"

using namespace std::chrono;

inline uint64_t calculate_max_digits() {
  const uint64_t max_fifth_power = std::pow(9, 5);
  uint64_t digits = 1;

  while (max_fifth_power * digits >= std::pow(10, digits)) {
    digits++;
  }

  return max_fifth_power * (digits - 1);
}

inline void solve_p30() {
  auto start = steady_clock::now();

  const uint64_t limit = calculate_max_digits();
  uint64_t answer = 0;
  uint64_t sum_fifths = 0;
  uint64_t tmp = 0;

  for (uint64_t i = 1; i < limit; i++) {
    tmp = i;

    while (tmp > 0) {
      sum_fifths += std::pow(tmp % 10, 5);
      tmp /= 10;
    }

    if (i == sum_fifths) {
      answer += i;
    }

    sum_fifths = 0;
  }

  auto end = steady_clock::now();

  std::cout << "Sum of special fifth-power digit-sums: " << answer << "\n";

  stopwatch(start, end);
}
