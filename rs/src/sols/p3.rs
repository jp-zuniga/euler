// https://projecteuler.net/problem=3
// -------------------------------------------------------------------------------------
// Find the largest prime factor of 600,851,475,143.

use std::time::Instant;

use crate::utils::primes::prime_factors_of;
use crate::utils::stopwatch;

#[inline]
pub fn solve_p3() {
    const BIG_NUM: u64 = 600_851_475_143;

    let start = Instant::now();
    let answer = prime_factors_of(BIG_NUM)
        .into_iter()
        .max()
        .expect("iterator shouldn't be empty!");

    let duration = start.elapsed();

    println!("{answer}");
    stopwatch(duration);
}
