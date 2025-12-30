// https://projecteuler.net/problem=3
// -------------------------------------------------------------------------------------
// Find the largest prime factor of 600851475143.

#include <algorithm>
#include <chrono>
#include <cstdint>
#include <iostream>
#include <vector>

#include "include/primality.hpp"
#include "include/stopwatch.hpp"

using namespace std::chrono;

inline void solve_p3() {
  auto start = steady_clock::now();

  constexpr uint64_t big_num = 600851475143;
  uint64_t largest_factor = 0;

  std::vector<uint64_t> factors = prime_factors(big_num);

  for (const uint64_t &factor : factors) {
    largest_factor = std::max(factor, largest_factor);
  }

  auto end = steady_clock::now();

  std::cout << "Largest prime factor of " << big_num << ": " << largest_factor
            << "\n";

  stopwatch(start, end);
}
