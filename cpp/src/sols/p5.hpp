// https://projecteuler.net/problem=5
// -------------------------------------------------------------------------------------
// Find the smallest number evenly divisible by all numbers from 1 to 20.

#include <chrono>
#include <cstdint>
#include <iostream>

#include "include/math-utils.hpp"
#include "include/stopwatch.hpp"

using namespace std::chrono;

inline void solve_p5() {
  auto start = steady_clock::now();

  constexpr uint64_t n = 2e1;
  uint64_t answer = 1;

  for (uint64_t i = 1; i <= n; i++) {
    // find the least common multiple of all numbers from 1 to n
    answer = lcm(answer, i);
  }

  auto end = steady_clock::now();

  std::cout << "Smallest number evenly divisible by all numbers from 1 to " << n
            << ": " << answer << "\n";

  stopwatch(start, end);
}
