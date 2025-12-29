// Problem URL: https://projecteuler.net/problem=4
// --------------------------------------------------------------------------------
// Find the largest palindrome made from the product of two 3-digit numbers.

#include <chrono>
#include <cstdint>
#include <iostream>

#include "include/timer.hpp"

inline bool is_palindrome(uint64_t num) {
  if (num < 10) {
    // single-digit numbers are automatically palindromes
    return true;
  }

  if (num % 10 == 0) {
    // num's last digit is 0, so it can't be a palindrome
    return false;
  }

  uint64_t reversed = 0;

  // algorithm for numerically reversing num:
  // -> make space for a new digit in reversed
  // -> extract num's last digit
  // -> add it to reversed
  // -> remove it from num

  // only reverse half of num's digits
  while (num > reversed) {
    reversed = (reversed * 10) + (num % 10);
    num /= 10;
  }

  // when the loop ends, there's two possibilities:
  //  1) if num has an even number of digits, then
  //     num and reversed are the same length,
  //     and they can be directly compared
  //
  // 2) if num has an odd number of digits, reversed will end the loop with
  //    one more digit than num, since the condition is num > reversed.
  //    however, that extra digit is num's middle digit, which when
  //    reversed is still the middle digit, so it can be ignored.

  // these two conditions cover both
  return (num == reversed) || (num == reversed / 10);
}

inline void solve_p4() {
  auto start = std::chrono::steady_clock::now();

  constexpr uint64_t upper_bound = 1e3 - 1;
  constexpr uint64_t lower_bound = 1e2;
  uint64_t largest_pal = 0;

  // check bigger numbers, and thus bigger products, first
  for (uint64_t i = upper_bound; i >= lower_bound; i--) {
    if (i * upper_bound < largest_pal) {
      // if i's largest possible product is too small
      // `biggest_pal` must've been found already
      break;
    }

    for (uint64_t j = upper_bound; j >= i; j--) {
      uint64_t product = i * j;

      if (product <= largest_pal) {
        // don't bother checking smaller products
        break;
      }

      if (is_palindrome(product)) {
        largest_pal = product;
      }
    }
  }

  auto end = std::chrono::steady_clock::now();

  std::cout
      << "Largest palindrome made from the product of two 3-digit numbers: "
      << largest_pal << "\n";

  print_time(start, end);
}
