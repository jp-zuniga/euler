// https://projecteuler.net/problem=15
// -------------------------------------------------------------------------------------
// In a 20x20 grid, how many unique routes are there from the upper left corner
// to the bottom right corner, when the only allowed moves are right and down?

use std::time::Instant;

use crate::utils::math::nCr;
use crate::utils::stopwatch;

#[inline]
pub fn solve_p15() {
    const R: u64 = 20;
    const N: u64 = 2 * R;

    let start = Instant::now();
    let answer = nCr(N, R);
    let duration = start.elapsed();

    println!("{answer}");
    stopwatch(duration);
}
