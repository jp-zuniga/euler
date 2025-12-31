// https://projecteuler.net/problem=27
// -------------------------------------------------------------------------------------
// Considering quadratics of the form:
// n^2 + an + b, where |a| < 1000, |b| <= 1000, n >= 0
// -------------------------------------------------------------------------------------
// Find the product of the coefficients, a and b, that produces the
// maximum number of primes for consecutive values of n.

// optimize!

#include <chrono>
#include <cmath>
#include <cstdint>
#include <iostream>

#include "include/primality.hpp"
#include "include/stopwatch.hpp"

using namespace std::chrono;

inline void solve_p27() {
  auto start = steady_clock::now();

  constexpr int64_t coeff_limit = 1e3;
  int64_t n = 0;
  int64_t max_consecutives = 0;
  int64_t max_a = 0;
  int64_t max_b = 0;

  // brute force approach:
  // check all combinations of a and b within the bounds given

  for (int64_t a = -coeff_limit; a < coeff_limit; a++) {
    for (int64_t b = -coeff_limit; b <= coeff_limit; b++) {
      n = 0;

      while (is_prime(std::abs(n * n + a * n + b))) {
        n++;
      }

      if (n > max_consecutives) {
        max_a = a;
        max_b = b;
        max_consecutives = n;
      }
    }
  }

  int64_t product = max_a * max_b;

  auto end = steady_clock::now();

  std::cout << "Product of prime-generating coefficients: " << product << "\n";

  stopwatch(start, end);
}
