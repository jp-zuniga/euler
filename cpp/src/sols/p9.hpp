// https://projecteuler.net/problem=9
// -------------------------------------------------------------------------------------
// Pythagorean triplet: 3 natural numbers for which:
//   - a < b < c
//   - a^2 + b^2 = c^2
// -------------------------------------------------------------------------------------
// Find the product of the pythagorean triplet for which a + b + c = 1,000.

// simplify to one loop by creating equations for a and b in terms of c?

#include <chrono>
#include <cstdint>
#include <iostream>

#include "include/stopwatch.hpp"

using namespace std::chrono;

inline void solve_p9() {
  auto start = steady_clock::now();

  constexpr uint64_t abc_sum = 1e3;
  uint64_t product = 1;
  uint64_t a = 0;

  // since c != b != a, and c is the largest,
  // c must be greater than a third of the desired sum
  // (e.g. the triangle is not isosceles and c is the hypotenuse)
  for (uint64_t c = (abc_sum / 3) + 1; c <= abc_sum - 2; c++) {
    for (uint64_t b = 1; b < c; b++) {
      // rearrange for a
      a = abc_sum - b - c;

      // ensure it's a pythagorean triplet
      // and meets problem requirements
      if ((a < b) && (a + b + c == abc_sum) && (a * a + b * b == c * c)) {
        product = a * b * c;

        auto end = steady_clock::now();

        std::cout << "Product of special Pythagorean triplet: " << product
                  << "\n";

        // exit loops immediately
        stopwatch(start, end);
        return;
      }
    }
  }
}
