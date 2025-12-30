// https://projecteuler.net/problem=35
// --------------------------------------------------------------------------------------
// Circular primes are primes that remain prime for all rotations of their
// digits.
// --------------------------------------------------------------------------------------
// Find all the circular primes below 1 million.

// optimize < 5ms

#include <chrono>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>

#include "include/primality.hpp"
#include "include/stopwatch.hpp"

using namespace std::chrono;

inline bool has_problem_digits(uint64_t num) {
  // if num has any even digits,
  // or one of its digits is 5,
  // one of its rotations will end in that digit,
  // which means it can't be prime and num can't be circular

  // by checking to see if num has these digits before
  // calculating its rotations saves unnecessary computations

  uint64_t digit = 0;

  while (num > 0) {
    digit = num % 10;
    if (digit == 5 || digit % 2 == 0) {
      return true;
    }

    num /= 10;
  }

  return false;
}

inline bool is_circular(const std::vector<uint64_t> &powers,
                        const std::vector<bool> &sieve, uint64_t num) {
  if (num < 10) {
    return true;
  }

  uint64_t num_digits = static_cast<uint64_t>(std::log10(num) + 1);

  // calculate the next rotation by shifting digits:
  // -> extract num's last digit
  // -> multiply last digit by 10^(num_digits - 1)
  // -> this makes space by adding zeroes to num
  // -> add num's remaining digits

  // ex:
  // num = 12,345;
  // num_digits = 5;
  // next_rotation = (5 * 10^4) + (12,345 / 10)
  //               = (50,000) + (1,234)
  //               = 51,234

  // loop for num_digits to find all possible rotations
  for (uint64_t i = 0; i < num_digits; i++) {
    num = ((num % 10 * powers[num_digits - 1]) + (num / 10));

    if (!sieve[num / 2]) {
      // if any rotation isn't in the prime sieve, exit early
      return false;
    }
  }

  // all rotations are prime
  return true;
}

inline void solve_p35() {
  auto start = steady_clock::now();

  constexpr uint64_t limit = 1e6;

  // cache necessary powers of 10 for is_circular(),
  // which are dependent on limit's amount of digits
  const uint64_t digit_limit = static_cast<uint64_t>(std::log10(limit) + 1);

  std::vector<uint64_t> powers;
  powers.reserve(digit_limit + 1);

  for (uint8_t i = 0; i <= digit_limit; i++) {
    powers.emplace_back(static_cast<uint64_t>(std::pow(10, i)));
  }

  // include 2
  uint64_t circular_count = 1;
  uint64_t prime = 0;

  std::vector<bool> primes = prime_sieve(limit);

  for (size_t i = 0; i < primes.size(); i++) {
    if (!primes[i]) {
      continue;
    }

    // convert index to its corresponding number
    prime = 2 * i + 1;

    if (prime < 10) {
      // single-digit primes are automatically circular
      circular_count++;
      continue;
    }

    if (has_problem_digits(prime)) {
      // this means the number has a digit that would
      // cause a rotation ending with it to not be prime
      continue;
    }

    if (is_circular(powers, primes, prime)) {
      circular_count++;
    }
  }

  auto end = steady_clock::now();

  std::cout << "Number of circular primes below " << limit << ": "
            << circular_count << "\n";

  stopwatch(start, end);
}
