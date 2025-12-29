// Problem URL: https://projecteuler.net/problem=6
// --------------------------------------------------------------------------------
// Find the difference between the sum of the squares and
// the square of the sum of the first 100 natural numbers.

#include <chrono>
#include <cstdint>
#include <iostream>

#include "include/timer.hpp"

inline void solve_p6() {
  auto start = std::chrono::steady_clock::now();

  constexpr uint64_t limit = 1e2;

  uint64_t square_of_sum = (limit * (limit + 1)) / 2;
  square_of_sum *= square_of_sum;
  uint64_t sum_of_squares = ((limit * (2 * limit + 1) * (limit + 1)) / 6);
  uint64_t answer = square_of_sum - sum_of_squares;

  auto end = std::chrono::steady_clock::now();

  std::cout << "Difference between sum of squares and squared sum: " << answer
            << "\n";

  print_time(start, end);
}
