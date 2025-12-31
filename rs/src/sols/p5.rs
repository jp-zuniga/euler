// https://projecteuler.net/problem=5
// -------------------------------------------------------------------------------------
// Find the smallest number evenly divisible by all numbers from 1 to 20.

use std::time::Instant;

use crate::utils::math::lcm;
use crate::utils::stopwatch;

#[inline]
pub fn solve_p5() {
    const N: u64 = 21;

    let start = Instant::now();

    let mut answer = 1;

    for i in 1..N {
        answer = lcm(answer, i);
    }

    let duration = start.elapsed();

    println!("{answer}");
    stopwatch(duration);
}
