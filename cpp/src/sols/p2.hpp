// Problem URL: https://projecteuler.net/problem=2
// --------------------------------------------------------------------------------
// Find the sum of all the even Fibonacci numbers below 4 million.

#include <chrono>
#include <cstdint>
#include <iostream>

#include "include/timer.hpp"

inline uint64_t sum_even_fibs(const uint64_t &limit) {
  // there's no need to use conditionals to check for evenness,
  // since it's known that every 3rd Fibonacci number is even.

  // however, since the sequence starts at F-0 = 0,
  // this implies that F-2 would be even, but F-2 = 1,
  // so it's more accurate to say that F-n
  // is even when n is a multiple of 3

  // start with F-1
  uint64_t a = 1;
  uint64_t b = 1;
  uint64_t c = a + b;
  uint64_t fib_sum = 0;

  while (c < limit) {
    fib_sum += c;
    a = b + c;
    b = c + a;
    c = a + b;
  }

  return fib_sum;
}

inline void solve_p2() {
  auto start = std::chrono::steady_clock::now();

  constexpr uint64_t limit = 4e6;
  uint64_t answer = sum_even_fibs(limit);

  auto end = std::chrono::steady_clock::now();

  std::cout << "Sum of all even Fibonacci numbers below " << limit << ": "
            << answer << "\n";

  print_time(start, end);
}
