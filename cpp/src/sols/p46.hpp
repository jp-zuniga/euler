// https://projecteuler.net/problem=46
// --------------------------------------------------------------------------------------
// Find the smallest odd composite number that cannot
// be written as the sum of a prime and twice a square.

// optimize!

#include <chrono>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>

#include "include/primality.hpp"
#include "include/timer.hpp"

using namespace std::chrono;

inline bool check_conjecture(const std::vector<bool> &sieve,
                             const uint64_t &num) {
  uint64_t prime = 0;
  uint64_t double_square = 0;
  uint64_t square = 0;
  uint64_t root = 0;

  for (size_t i = 0; i < sieve.size(); i++) {
    if (!sieve[i]) {
      continue;
    }

    prime = 2 * i + 1;

    if (prime > num) {
      // all possible combinations must've been checked,
      // and the conjecture has already been disproven
      break;
    }

    double_square = num - prime;

    if (double_square % 2 == 0) {
      square = double_square / 2;
      root = static_cast<uint64_t>(std::sqrt(square));

      if (root * root == square) {
        return true;
      }
    }
  }

  return false;
}

inline void solve_p46() {
  auto start = steady_clock::now();

  constexpr uint64_t prime_limit = 1e6;

  // cache primes to know which odd integers are composites
  std::vector<bool> sieve = prime_sieve(prime_limit);

  uint64_t composite = 0;

  // skip 1
  for (size_t i = 1; i < sieve.size(); i++) {
    if (sieve[i]) {
      continue;
    }

    composite = 2 * i + 1;

    if (!check_conjecture(sieve, composite)) {
      break;
    }
  }

  auto end = steady_clock::now();

  std::cout << "Smallest odd composite number that disproves Goldbach's "
               "other conjecture: "
            << composite << "\n";

  print_time(start, end);
}
