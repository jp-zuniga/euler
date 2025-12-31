// https://projecteuler.net/problem=1
// -------------------------------------------------------------------------------------
// Find the sum of all the multiples of 3 and 5 below 1,000.

use std::time::Instant;

use crate::utils::math::lcm;
use crate::utils::stopwatch;

#[inline]
const fn sum_divisible_by_n(limit: u64, n: u64) -> u64 {
    let x = limit / n;

    (n * x * (x + 1)) / 2
}

#[inline]
pub fn solve_p1() {
    const LIMIT: u64 = 1_000;
    const A: u64 = 3;
    const B: u64 = 5;

    let start = Instant::now();

    let answer = sum_divisible_by_n(LIMIT, A) + sum_divisible_by_n(LIMIT, B)
        - sum_divisible_by_n(LIMIT, lcm(A, B));

    let duration = start.elapsed();

    println!("{answer}");
    stopwatch(duration);
}
