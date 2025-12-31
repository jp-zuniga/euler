// https://projecteuler.net/problem=14
// -------------------------------------------------------------------------------------
// Collatz Sequence:
//   - even n: n -> n / 2
//   - odd n:  n -> 3n + 1
// -------------------------------------------------------------------------------------
// Find the starting number, under 1 million, that makes the longest sequence.

use std::time::Instant;

use rayon::iter::{IntoParallelIterator, ParallelIterator};

use crate::utils::stopwatch;

#[inline]
pub fn solve_p14() {
    const LIMIT: u32 = 1_000_000;

    let start = Instant::now();

    let (answer, _) = (2..LIMIT)
        .into_par_iter()
        .map(|i| {
            let mut n: u32 = i;
            let mut len: u32 = 1;

            while n != 1 {
                len += 1;

                if n.is_multiple_of(2) {
                    n /= 2;
                } else {
                    n = (3 * n) + 1;
                }
            }

            (i, len)
        })
        .max_by(|(_, x), (_, y)| x.cmp(y))
        .expect("iterator shouldn't be empty!");

    let duration = start.elapsed();

    println!("{answer}");
    stopwatch(duration);
}
