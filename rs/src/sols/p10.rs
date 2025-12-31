// https://projecteuler.net/problem=10
// -------------------------------------------------------------------------------------
// Find the sum of all primes below 2 million.

// optimize!

use std::time::Instant;

use crate::utils::primes::prime_sieve_up_to;
use crate::utils::stopwatch;

#[inline]
pub fn solve_p10() {
    const LIMIT: u64 = 2_000_000;

    let start = Instant::now();

    let answer: u64 = prime_sieve_up_to(LIMIT)
        .into_iter()
        .enumerate()
        .filter_map(|(i, is_prime)| {
            if is_prime {
                Some(2 * (i as u64) + 1)
            } else {
                None
            }
        })
        .sum();

    let duration = start.elapsed();

    println!("{answer}");
    stopwatch(duration);
}
