// https://projecteuler.net/problem=21
// -------------------------------------------------------------------------------------
// Amicable numbers: numbers whose sum of divisors are
// equal to each other (but the numbers are not equal)
// -------------------------------------------------------------------------------------
// Find the sum of all amicable numbers below 10,000.

// optimize < 1ms

#include <chrono>
#include <cstdint>
#include <iostream>

#include "include/math-utils.hpp"
#include "include/stopwatch.hpp"

using namespace std::chrono;

inline void solve_p21() {
  auto start = steady_clock::now();

  constexpr uint64_t limit = 1e4;
  uint64_t amicable_sum = 0;
  uint64_t b = 0;

  for (uint64_t a = 1; a < limit; a++) {
    b = sum_divisors(a);

    if (a != b && a == sum_divisors(b)) {
      amicable_sum += a;
    }
  }

  auto end = steady_clock::now();

  std::cout << "Sum of all amicable numbers under " << limit << ": "
            << amicable_sum << "\n";

  stopwatch(start, end);
}
