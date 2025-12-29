#include <algorithm>
#include <cstdint>
#include <vector>

inline bool is_prime(const uint64_t &num) {
  // - use a lookup table for small primes
  // - only check composite numbers in the form 6k ± 1

  static const std::vector<uint64_t> prime_lookup = {
      2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,  41,  43,
      47,  53,  59,  61,  67,  71,  73,  79,  83,  89,  97,  101, 103, 107,
      109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181,
      191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263,
      269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
      353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433,
      439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521,
      523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613,
      617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701,
      709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809,
      811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887,
      907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997,
  };

  // skip easy answers
  if (num < 2 || num % 2 == 0) {
    return false;
  }

  // look up small primes
  if (num < 1000) {
    return std::binary_search(prime_lookup.begin(), prime_lookup.end(), num);
  }

  // check divisibility by small primes (except 2)
  for (size_t i = 1; i < prime_lookup.size(); i++) {
    if (num % prime_lookup[i] == 0) {
      return false;
    }
  }

  // there's no need to check composite divisors because if
  // num is divisible by a composite number, it must also
  // be divisible by that number's prime factors.

  // this loop only checks primes of the form 6k ± 1 since
  // all primes greater than 3 can be expressed that way

  for (uint64_t i = 1001; i * i <= num; i += 6) {
    // check 6k - 1
    if (num % i == 0) {
      return false;
    }

    // check 6k + 1
    uint64_t j = i + 2;

    if (j * j > num) {
      // if j is bigger than sqrt(num), all
      // subsequent i will be too, which means
      // all possible divisors have been checked
      break;
    }

    if (num % j == 0) {
      return false;
    }
  }

  return true;
}

inline std::vector<bool> prime_sieve(const uint64_t &num) {
  // implementation of the sieve of eratosthenes
  // - only represents odd numbers
  // - returns a vector half the size of `num`
  // - any index, n, maps to 2n + 1

  // optimize to only represent integers of the form 6k ± 1?
  // convert to return a std::array since it's a fixed size?

  if (num <= 2) {
    return std::vector<bool>((num + 1) / 2, false);
  }

  // only bother representing odd numbers < num
  // index n = 2n + 1
  std::vector<bool> sieve((num + 1) / 2, true);

  // 1 isn't prime
  sieve[0] = false;

  // only loop over odd numbers
  for (uint64_t i = 3; i * i <= num; i += 2) {
    if (!sieve[i / 2]) {
      continue;
    }

    for (uint64_t j = i * i; j <= num; j += 2 * i) {
      // set all multiples of i to false
      // increment by 2*i to avoid even multiples
      sieve[j / 2] = false;
    }
  }

  return sieve;
}

inline std::vector<uint64_t> prime_factors(uint64_t num) {
  // find prime factors through prime factorization,
  // - only check composite numbers in the form 6k ± 1

  std::vector<uint64_t> factors;

  // deal with all even factors
  while (num % 2 == 0) {
    factors.emplace_back(2);
    num /= 2;
  }

  // deal with all factors of 3
  while (num % 3 == 0) {
    factors.emplace_back(3);
    num /= 3;
  }

  if (num == 1) {
    // all factors have been found
    return factors;
  }

  // optimize loop by avoiding factors of 2 and 3 (removed already)
  // and only check integers of the form 6k ± 1 starting from 5
  // since all primes (> 3) can be expressed that way

  for (uint64_t i = 5; i * i <= num; i += 6) {
    while (num % i == 0) {
      // factor out 6k - 1
      factors.emplace_back(i);
      num /= i;
    }

    // 6k + 1
    uint64_t j = i + 2;
    if (j * j > num) {
      // this means any subsequent i can't be a divisor of num,
      // and num itself must be prime since all
      // possible divisors have been removed
      break;
    }

    while (num % j == 0) {
      factors.emplace_back(j);
      num /= j;
    }
  }

  if (num > 3) {
    // num must be prime and the last prime factor
    factors.emplace_back(num);
  }

  return factors;
}
