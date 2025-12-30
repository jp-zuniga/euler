// https://projecteuler.net/problem=145
// --------------------------------------------------------------------------------------
// Reversible numbers are numbers for which (n + reverse(n)) has only odd
// numbers.
// --------------------------------------------------------------------------------------
// Find how many reversible numbers exist below 1 billion.

// optimize!

#include <chrono>
#include <cstdint>
#include <iostream>

#include "include/timer.hpp"

using namespace std::chrono;

inline uint64_t reverse(uint64_t num) {
  uint64_t reversed = 0;

  while (num > 0) {
    // make space for a new digit in reversed
    // so num's last digit can be added,
    // then remove that digit from num
    reversed = (reversed * 10) + (num % 10);
    num /= 10;
  }

  return reversed;
}

inline bool all_odd_digits(uint64_t num) {
  // check all of num's digits for evenness
  while (num > 0) {
    if (num % 2 == 0) {
      return false;
    }

    // remove last digit
    num /= 10;
  }

  return true;
}

inline bool is_reversible(const uint64_t &num) {
  return all_odd_digits(num + reverse(num));
}

inline void solve_p145() {
  auto start = steady_clock::now();

  constexpr uint64_t limit = 1e9;
  uint64_t count = 0;

  // skip single-digit numbers and all even numbers
  for (uint64_t i = 11; i < limit; i += 2) {
    if (is_reversible(i)) {
      // for i + reverse(i) to only have odd digits,
      // i must only have odd digits and reverse(i) only even digits
      // this means that reverse(i) will never be encountered by the loop
      // so when a reversible number is found, also count its reverse
      count += 2;
    }
  }

  auto end = steady_clock::now();

  std::cout << "Reversible numbers below " << limit << ": " << count << "\n";

  print_time(start, end);
}
