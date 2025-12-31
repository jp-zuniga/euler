// https://projecteuler.net/problem=13
// -------------------------------------------------------------------------------------
// Find the first 10 digits of the sum of all the 50-digit numbers.

use std::time::Instant;

use crate::utils::stopwatch;

#[inline]
pub fn solve_p13() {
    const NUMS: &str = include_str!("../../../inputs/13-numbers.txt");

    let start = Instant::now();

    let answer = NUMS
        .split(',')
        .filter_map(|s| s[0..12].parse::<u64>().ok())
        .sum::<u64>()
        .to_string()
        .get(0..10)
        .expect("result shouldn't be empty!")
        .to_string();

    let duration = start.elapsed();

    println!("{answer}");
    stopwatch(duration);
}
