// https://projecteuler.net/problem=8
// -------------------------------------------------------------------------------------
// Reversible numbers are numbers for which (n + reverse(n)) has only odd numbers.
// -------------------------------------------------------------------------------------
// Find how many reversible numbers exist below 1 billion.

use std::time::Instant;

use rayon::iter::{IndexedParallelIterator, IntoParallelIterator, ParallelIterator};

use crate::utils::stopwatch;

#[inline]
const fn all_odd_digits(mut num: u32) -> bool {
    while num > 0 {
        if num.is_multiple_of(2) {
            return false;
        }

        num /= 10;
    }

    true
}

#[inline]
const fn reverse(mut num: u32) -> u32 {
    let mut reversed: u32 = 0;

    while (num > 0) {
        reversed = (reversed * 10) + (num % 10);
        num /= 10;
    }

    reversed
}

#[inline]
const fn is_reversible(mut num: u32) -> bool {
    all_odd_digits(num + reverse(num))
}

#[inline]
pub fn solve_p145() {
    // there are no solutions between 10^8 and 10^9
    const LIMIT: u32 = 100_000_000;

    let start = Instant::now();

    let answer = (11..LIMIT)
        .into_par_iter()
        .step_by(2)
        .filter(|&x| is_reversible(x))
        .count()
        * 2;

    let duration = start.elapsed();

    println!("{answer}");
    stopwatch(duration);
}
