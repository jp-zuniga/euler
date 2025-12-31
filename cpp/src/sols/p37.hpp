// https://projecteuler.net/problem=37
// -------------------------------------------------------------------------------------
// Truncatable primes are primes that can continuously have
// their digits removed from either side and still be prime.
// -------------------------------------------------------------------------------------
// Find the sum of all truncatable primes.

// optimize!

#include <chrono>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>

#include "include/primality.hpp"
#include "include/stopwatch.hpp"

using namespace std::chrono;

inline bool is_truncatable(const std::vector<uint64_t> &powers,
                           const std::vector<bool> &sieve,
                           const uint64_t &num) {
  if (num < 10) {
    return false;
  }

  uint64_t num_digits = static_cast<uint64_t>(std::log10(num) + 1);

  uint64_t left_trunc = num;
  uint64_t right_trunc = num;

  // avoid removing the last digit
  for (uint64_t i = num_digits; i > 0; i--) {
    if (i != 1) {
      left_trunc %= powers[i - 1];
      right_trunc /= 10;
    }

    if ((left_trunc != 2 && left_trunc % 2 == 0) ||
        (right_trunc != 2 && right_trunc % 2 == 0)) {
      // handle the possibility that the truncations
      // could be even before accessing the sieve,
      // since it only represents odd numbers
      return false;
    }

    // even though 2 is not included in the sieve,
    // it doesn't matter if one or both of the truncations is 2,
    // since 2/1 = 1, and sieve[1] corresponds to 3, which
    // means 2 will still be identified as prime

    if (!sieve[left_trunc / 2] || !sieve[right_trunc / 2]) {
      return false;
    }
  }

  return true;
}

inline void solve_p37() {
  auto start = steady_clock::now();

  constexpr uint64_t limit = 1e6;

  // cache necessary powers of 10 for is_truncatable(),
  // which are dependent on limit's number of digits
  const uint64_t digit_limit = static_cast<uint64_t>(std::log10(limit) + 1);

  std::vector<uint64_t> powers;
  powers.reserve(digit_limit + 1);

  for (uint8_t i = 0; i <= digit_limit; i++) {
    powers.emplace_back(static_cast<uint64_t>(std::pow(10, i)));
  }

  uint64_t prime = 0;
  uint64_t sum_truncs = 0;

  std::vector<bool> primes = prime_sieve(limit);

  for (size_t i = 0; i < primes.size(); i++) {
    if (!primes[i]) {
      continue;
    }

    prime = 2 * i + 1;

    if (prime < 10) {
      continue;
    }

    if (is_truncatable(powers, primes, prime)) {
      sum_truncs += prime;
    }
  }

  auto end = steady_clock::now();

  std::cout << "Sum of all truncatable primes less than " << limit << ": "
            << sum_truncs << "\n";

  stopwatch(start, end);
}
