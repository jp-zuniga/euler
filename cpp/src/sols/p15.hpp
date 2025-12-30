// https://projecteuler.net/problem=15
// -------------------------------------------------------------------------------------
// In a 20x20 grid, how many unique routes are there from the upper left corner
// to the bottom right corner, when the only allowed moves are right and down?

#include <chrono>
#include <cstdint>
#include <iostream>

#include "include/math-utils.hpp"
#include "include/stopwatch.hpp"

using namespace std::chrono;

inline void solve_p15() {
  auto start = steady_clock::now();

  // dimensions of the grid
  constexpr uint64_t r = 2e1;
  constexpr uint64_t n = 2 * r;

  // the total number of moves that have to be made is 40,
  // 20 moves right and 20 moves down, so the problem boils
  // down to the number of ways to arrange those moves,
  // which corresponds to the combination function:
  // n! / (r!(n - r)!)
  // "from 40 possible moves, how many ways can 20 of them be arranged?"

  // since the moves are functionally identical, we only care about
  // the possible arrangements for one set of moves (right or down),
  // since the other 20 will fill in the slots that are left

  uint64_t answer = nCr(n, r);

  auto end = steady_clock::now();

  std::cout << "Number of possible routes: " << answer << "\n";

  stopwatch(start, end);
}
