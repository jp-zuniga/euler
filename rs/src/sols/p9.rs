// https://projecteuler.net/problem=9
// -------------------------------------------------------------------------------------
// A Pythagorean triplet is a group of 3 natural numbers for which:
//   - a < b < c
//   - a^2 + b^2 = c^2
// -------------------------------------------------------------------------------------
// Find the product of the pythagorean triplet for which a + b + c = 1,000.

use std::time::Instant;

use crate::utils::stopwatch;

#[inline]
fn find_triplet_prod(limit: u32) -> Option<u32> {
    for c in ((limit / 3) + 1)..(limit - 2) {
        for b in 1..c {
            let a = limit - b - c;

            if a < b && (a + b + c == limit) && (a * a + b * b == c * c) {
                return Some(a * b * c);
            }
        }
    }

    None
}

#[inline]
pub fn solve_p9() {
    const LIMIT: u32 = 1_000;

    let start = Instant::now();
    let answer = find_triplet_prod(LIMIT).expect("an answer should be found!");
    let duration = start.elapsed();

    println!("{answer}");
    stopwatch(duration);
}
