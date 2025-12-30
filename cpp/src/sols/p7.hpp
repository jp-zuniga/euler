// https://projecteuler.net/problem=7
// -------------------------------------------------------------------------------------
// Find the 10,001st prime number.

#include <chrono>
#include <cmath>
#include <cstdint>
#include <iostream>

#include "include/primality.hpp"
#include "include/timer.hpp"

using namespace std::chrono;

inline void solve_p7() {
  auto start = steady_clock::now();

  constexpr uint64_t prime_index = 1e4 + 1;

  // use the prime number theorem:
  // the nth prime is approximately equal to n*log(n)
  // scale this result by 1.25 to have a margin of error
  const uint64_t upper_bound =
      static_cast<uint64_t>(1.25 * prime_index * std::log(prime_index));

  std::vector<bool> sieve = prime_sieve(upper_bound);

  uint64_t answer = 0;

  // count 2 since it's not in the sieve
  uint64_t counter = 1;

  for (size_t i = 0; i < sieve.size(); i++) {
    if (sieve[i]) {
      counter++;
    }

    if (counter == prime_index) {
      answer = 2 * i + 1;
      break;
    }
  }

  auto end = steady_clock::now();

  std::cout << "Prime #" << prime_index << ": " << answer << "\n";

  print_time(start, end);
}
