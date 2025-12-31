// https://projecteuler.net/problem=6
// -------------------------------------------------------------------------------------
// Find the difference between the sum of the squares and
// the square of the sum of the first 100 natural numbers.

use std::time::Instant;

use crate::utils::stopwatch;

#[inline]
const fn square_sum(n: u64) -> u64 {
    let sum = (n * (n + 1)) / 2;

    sum * sum
}

#[inline]
const fn sum_squares(n: u64) -> u64 {
    (n * (2 * (n + 1)) * (n + 1)) / 6
}

#[inline]
pub fn solve_p6() {
    const LIMIT: u64 = 100;

    let start = Instant::now();
    let answer = square_sum(LIMIT) - sum_squares(LIMIT);
    let duration = start.elapsed();

    println!("{answer}");
    stopwatch(duration);
}
