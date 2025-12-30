#[inline]
pub fn is_prime(num: u64) -> bool {
    static PRIME_LOOKUP: &[u64] = &[
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73,
        79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157,
        163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241,
        251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347,
        349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439,
        443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547,
        557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643,
        647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751,
        757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859,
        863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977,
        983, 991, 997,
    ];

    // easy mode
    if num == 1 || num.is_multiple_of(2) {
        return false;
    }

    // cached prime
    if PRIME_LOOKUP.binary_search(&num).is_ok() {
        return true;
    }

    // divisible by cached prime (excluding 2)
    if PRIME_LOOKUP[1..].iter().any(|x| num.is_multiple_of(*x)) {
        return false;
    }

    // check divisibility by primes in the form 6k ± 1
    for i in (1001..).step_by(6).take_while(|&i| i * i <= num) {
        // 6k - 1
        if num.is_multiple_of(i) {
            return false;
        }

        // 6k + 2
        let j = i + 2;
        if j * j > num {
            // all possible divisors have been checked
            break;
        }

        if num.is_multiple_of(j) {
            return false;
        }
    }

    true
}

#[allow(clippy::cast_possible_truncation)]
#[inline]
pub fn prime_sieve(num: u64) -> Vec<bool> {
    let half = num.div_ceil(2) as usize;

    if num <= 2 {
        return vec![false; half];
    }

    let mut sieve = vec![true; half];

    sieve[0] = false;

    for i in (3..).step_by(2).take_while(|&i| i * i <= num) {
        if sieve[(i / 2) as usize] {
            for j in ((i * i)..)
                .step_by((2 * i) as usize)
                .take_while(|&j| j <= num)
            {
                // set all multiples of i to false
                sieve[(j / 2) as usize] = false;
            }
        }
    }

    sieve
}

#[inline]
pub fn prime_factors(mut num: u64) -> Vec<u64> {
    let mut factors = Vec::new();

    while num.is_multiple_of(2) {
        factors.push(2);
        num /= 2;
    }

    while num.is_multiple_of(3) {
        factors.push(3);
        num /= 3;
    }

    if num == 1 {
        return factors;
    }

    let mut i: u64 = 5;
    while i * i <= num {
        while num.is_multiple_of(i) {
            factors.push(i);
            num /= i;
        }

        let j = i + 2;
        if j * j > num {
            break;
        }

        while num.is_multiple_of(j) {
            factors.push(j);
            num /= j;
        }

        i += 6;
    }

    if num > 3 {
        // num must be prime
        factors.push(num);
    }

    factors
}
