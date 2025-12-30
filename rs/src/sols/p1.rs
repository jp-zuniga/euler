// https://projecteuler.net/problem=1
// -------------------------------------------------------------------------------------
// Find the sum of all the multiples of 3 and 5 below 1,000.

use std::time::Instant;

use crate::utils::{lcm, print_time};

const fn sum_divisible_by_n(limit: i32, n: i32) -> i32 {
    let x = limit / n;

    (n * x * (x + 1)) / 2
}

pub fn solve_p1() {
    const LIMIT: i32 = 1000;
    const A: i32 = 3;
    const B: i32 = 5;

    let start = Instant::now();

    let multiples_sum = -sum_divisible_by_n(LIMIT, lcm(A, B))
        + sum_divisible_by_n(LIMIT, A)
        + sum_divisible_by_n(LIMIT, B);

    let duration = start.elapsed();

    println!("Sum of all multiples of {A} and {B} below {LIMIT}: {multiples_sum}");
    print_time(duration);
}
