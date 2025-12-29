// Problem URL: https://projecteuler.net/problem=14
// ---------------------------------------------------------------------------------
// Collatz Sequence:
// n -> n/2 (if n is even)
// n -> 3n + 1 (if n is odd)
// ---------------------------------------------------------------------------------
// Find the starting number, under 1 million, that makes the longest sequence.

// optimize (how???)

#include <chrono>
#include <cstdint>
#include <iostream>

#include "include/timer.hpp"

inline void solve_p14() {
  auto start = std::chrono::steady_clock::now();

  constexpr uint64_t limit = 1e6;
  uint64_t longest_start_num = 0;
  uint64_t longest_seq = 0;
  uint64_t current_seq_length = 0;
  uint64_t n = 0;

  for (uint64_t i = 2; i < limit; i++) {
    n = i;
    current_seq_length = 0;

    // find the current n's sequence length
    while (n != 1) {
      if (n % 2 == 0) {
        n = n / 2;
      } else {
        n = 3 * n + 1;
      }

      current_seq_length++;
    }

    // update values
    if (current_seq_length > longest_seq) {
      longest_seq = current_seq_length;
      longest_start_num = i;
    }
  }

  auto end = std::chrono::steady_clock::now();

  std::cout << "Length of " << longest_start_num
            << "'s Collatz sequence: " << longest_seq << "\n";

  print_time(start, end);
}
