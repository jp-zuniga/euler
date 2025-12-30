// https://projecteuler.net/problem=39
// --------------------------------------------------------------------------------------
// Let p be the perimeter of a right-angle triangle with integer sides.
// For which value of p (<= 1000) is the number of solutions maximized?

// optimize!

#include <chrono>
#include <cstdint>
#include <iostream>

#include "include/timer.hpp"

using namespace std::chrono;

inline uint64_t count_solutions(const uint64_t &p) {
  const uint64_t third_perimeter = p / 3;
  const uint64_t half_perimeter = p / 2;

  uint64_t solutions = 0;
  uint64_t c = 0;

  // make sure a < b < c
  for (uint64_t a = 1; a < third_perimeter; a++) {
    for (uint64_t b = a; b < half_perimeter; b++) {
      c = p - a - b;

      // only count solutions that create a right-angled triangle
      if (a * a + b * b == c * c) {
        solutions++;
      }
    }
  }

  return solutions;
}

inline void solve_p39() {
  auto start = steady_clock::now();

  constexpr uint64_t limit = 1e3;
  uint64_t max_p = 0;
  uint64_t max_solutions = 0;
  uint64_t current_solutions = 0;

  // start at the minimum possible perimeter
  for (uint64_t p = 3; p <= limit; p++) {
    current_solutions = count_solutions(p);

    if (current_solutions > max_solutions) {
      max_solutions = current_solutions;
      max_p = p;
    }
  }

  auto end = steady_clock::now();

  std::cout << "Perimeter with the most solutions: " << max_p << "\n";

  print_time(start, end);
}
