// https://projecteuler.net/problem=45
// -------------------------------------------------------------------------------------
// Triangle, pentagonal, and hexagonal numbers have the following formulas:
// T-n = n(n + 1) / 2
// P-n = n(3n - 1) / 2
// H-n = n(2n - 1)
// -------------------------------------------------------------------------------------
// 40,755 is T-285, P-165, H-143.
// Find the next triangle number that is also pentagonal and hexagonal.

#include <chrono>
#include <cstdint>
#include <iostream>

#include "include/math-utils.hpp"
#include "include/timer.hpp"

using namespace std::chrono;

inline void solve_p45() {
  auto start = steady_clock::now();

  // since all hexagonal numbers are triangular numbers
  // (by virtue of being a subset of them), only a
  // pentagonal check is needed, since hexagonal numbers
  // can be generated continually until is_pentagonal() returns true

  // pick up from H-143
  uint64_t n = 143;
  uint64_t hexagonal = 0;
  uint64_t answer = 0;

  while (true) {
    n++;
    hexagonal = n * (2 * n - 1);

    if (is_pentagonal(hexagonal)) {
      answer = hexagonal;
      break;
    }
  }

  auto end = steady_clock::now();

  std::cout << "Next triangular number that is pentagonal and "
            << "hexagonal: " << answer << "\n";

  print_time(start, end);
}
