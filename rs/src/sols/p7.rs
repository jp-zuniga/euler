// https://projecteuler.net/problem=7
// -------------------------------------------------------------------------------------
// Find the 10,001st prime number.

use std::time::Instant;

use crate::utils::primes::prime_sieve_up_to;
use crate::utils::stopwatch;

#[allow(clippy::cast_possible_truncation)]
#[allow(clippy::cast_precision_loss)]
#[allow(clippy::cast_sign_loss)]
#[inline]
pub fn solve_p7() {
    const IDX: u64 = 10_001;
    const FDX: f64 = IDX as f64;
    const UDX: usize = (IDX - 2) as usize;

    let start = Instant::now();

    let bound: u64 = (1.25 * FDX * FDX.ln()) as u64;

    let answer = prime_sieve_up_to(bound)
        .into_iter()
        .enumerate()
        .filter_map(|(i, is_prime)| {
            if is_prime {
                Some(2 * i + 1)
            } else {
                None
            }
        })
        .nth(UDX)
        .expect("upper bound too low!");

    let duration = start.elapsed();

    println!("{answer}");
    stopwatch(duration);
}
