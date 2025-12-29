// Problem URL: https://projecteuler.net/problem=1
// --------------------------------------------------------------------------------
// Find the sum of all the multiples of 3 and 5 below 1,000.

#include <chrono>
#include <cstdint>
#include <iostream>

#include "include/math-utils.hpp"
#include "include/timer.hpp"

inline uint64_t sum_divisible_by_n(const uint64_t &limit, const uint64_t &n) {
  // the sum of all numbers up to a certain limit divisible by n
  // is a sequence where all numbers share a common factor of n,
  // which means once n is factored out, the sequence becomes:
  // n(1 + 2 + 3 + ... + limit / n)

  // the formula for such an arithmetic sequence is:
  // limit(limit + 1) / 2

  // once this is multiplied by n, what the
  // original sequence is equal to is found

  uint64_t x = limit / n;
  return (n * x * (x + 1)) / 2;
}

inline void solve_p1() {
  auto start = std::chrono::steady_clock::now();

  constexpr uint64_t limit = 1e3;
  constexpr uint64_t a = 3;
  constexpr uint64_t b = 5;

  // when adding all the multiples of a and b separately,
  // all the multiples of lcm(a, b) are added twice, which means
  // the sum of all those multiples must be subtracted from the answer

  // this is much more efficient than an iterative approach for large limits

  uint64_t multiples_sum =
      (sum_divisible_by_n(limit, a) + sum_divisible_by_n(limit, b) -
       sum_divisible_by_n(limit, lcm(a, b)));

  auto end = std::chrono::steady_clock::now();

  std::cout << "Sum of all multiples of 3 and 5 below " << limit << ": "
            << multiples_sum << "\n";

  print_time(start, end);
}
