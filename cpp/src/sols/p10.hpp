// https://projecteuler.net/problem=10
// -------------------------------------------------------------------------------------
// Find the sum of all primes below 2 million.

// optimizeee

#include <chrono>
#include <cstdint>
#include <iostream>

#include "include/primality.hpp"
#include "include/timer.hpp"

using namespace std::chrono;

inline void solve_p10() {
  auto start = steady_clock::now();

  constexpr uint64_t limit = 2e6;

  std::vector<bool> primes = prime_sieve(limit);

  // include 2, which isn't in the sieve
  uint64_t prime_sum = 2;

  for (size_t i = 0; i < primes.size(); i++) {
    if (primes[i]) {
      prime_sum += 2 * i + 1;
    }
  }

  auto end = steady_clock::now();

  std::cout << "Sum of all primes below " << limit << ": " << prime_sum << "\n";

  print_time(start, end);
}
