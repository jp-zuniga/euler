// https://projecteuler.net/problem=47
// -------------------------------------------------------------------------------------
// Find the first four consecutive integers to have four distinct prime
// factors each.

// optimize!

#include <iostream>
#include <unordered_set>
#include <vector>

#include "include/primality.hpp"
#include "include/stopwatch.hpp"

using namespace std::chrono;

inline void solve_p47() {
  auto start = steady_clock::now();

  uint64_t counter = 0;
  uint64_t i = 0;

  while (counter < 4) {
    i++;
    std::vector<uint64_t> factors = prime_factors(i);

    // convert to a set to automatically remove duplicates
    std::unordered_set<uint64_t> distinct_factors(factors.begin(),
                                                  factors.end());

    if (distinct_factors.size() >= 4) {
      counter++;
    } else {
      counter = 0;
    }
  }

  auto end = steady_clock::now();

  std::cout << "First of 4 consecutive integers to have "
            << "4 distinct prime factors each is: " << i - 3 << "\n";

  stopwatch(start, end);
}
