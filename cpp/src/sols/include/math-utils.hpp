#include <cmath>
#include <cstdint>

inline uint64_t gcd(uint64_t a, uint64_t b) {
  uint64_t tmp = 0;

  while (b != 0) {
    tmp = b;
    b = a % b;
    a = tmp;
  }

  return a;
}

inline uint64_t lcm(const uint64_t &a, const uint64_t &b) {
  return (a / gcd(a, b)) * b;
}

inline bool is_pentagonal(const uint64_t &n) {
  double pent = std::sqrt(24 * n + 1);
  uint64_t cast = static_cast<uint64_t>(pent);

  return (cast == pent && cast % 6 == 5 && cast > 0);
}

inline uint64_t nCr(const uint64_t &n, const uint64_t &r) {
  // tgammal is an implementation of the gamma function:
  // T(n) = (n - 1)!
  // cancel out -1 with (n+1)
  return static_cast<uint64_t>(std::tgammal(n + 1) /
                               (std::tgammal(r + 1) * std::tgammal(n - r + 1)));
}

inline uint64_t sum_divisors(uint64_t num) {
  // optimize!!!

  if (num <= 1) {
    return 0;
  }

  // for complementary divisors
  uint64_t comp = 0;
  uint64_t div_sum = 1;

  // handle even and odd num separately in order to optimize the
  // divisor loop for odd numbers by not bothering with even numbers

  if (num % 2 == 0) {
    div_sum += 2;
    comp = num / 2;

    if (2 != comp) {
      // avoid counting divisors twice
      div_sum += comp;
    }

    // only loop while i <= sqrt(num), or i^2 <= num,
    // since the sqrt is the largest possible divisor
    for (uint64_t i = 3; i * i <= num; i++) {
      if (num % i == 0) {
        div_sum += i;
        comp = num / i;

        if (i != comp) {
          div_sum += comp;
        }
      }
    }
  }

  else {
    // skip all even numbers
    for (uint64_t i = 3; i * i <= num; i += 2) {
      if (num % i == 0) {
        div_sum += i;
        comp = num / i;

        if (i != comp) {
          div_sum += comp;
        }
      }
    }
  }

  return div_sum;
}
