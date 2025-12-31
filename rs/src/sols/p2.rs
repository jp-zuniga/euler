// https://projecteuler.net/problem=2
// -------------------------------------------------------------------------------------
// Find the sum of all the even Fibonacci numbers below 4 million.

use std::time::Instant;

use crate::utils::stopwatch;

#[inline]
const fn sum_even_fibs(limit: i32) -> i32 {
    let mut sum = 0;
    let mut a = 1;
    let mut b = 1;
    let mut c = a + b;

    while b < limit {
        sum += c;
        a = b + c;
        b = c + a;
        c = a + b;
    }

    sum
}

#[inline]
pub fn solve_p2() {
    const LIMIT: i32 = 4_000_000;

    let start = Instant::now();
    let sum = sum_even_fibs(LIMIT);
    let duration = start.elapsed();

    println!("Sum of all even Fibonacci numbers below {LIMIT}: {sum}");
    stopwatch(duration);
}
