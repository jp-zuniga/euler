// https://projecteuler.net/problem=4
// -------------------------------------------------------------------------------------
// Find the largest palindrome made from the product of two 3-digit numbers.

use std::time::Instant;

use crate::utils::stopwatch;

#[inline]
const fn is_palindrome(mut num: u64) -> bool {
    if num < 10 {
        return true;
    }

    if num.is_multiple_of(10) {
        return false;
    }

    let mut reversed: u64 = 0;

    while (num > reversed) {
        reversed = (reversed * 10) + (num % 10);
        num /= 10;
    }

    (num == reversed) || (num == reversed / 10)
}

#[inline]
fn find_largest_pal(lower: u64, upper: u64) -> u64 {
    let mut largest = 0;

    for i in (lower..upper).rev() {
        if (i * upper) < largest {
            break;
        }

        for j in (i..upper).rev() {
            let product = i * j;

            if product <= largest {
                break;
            }

            if is_palindrome(product) {
                largest = product;
            }
        }
    }

    largest
}

#[inline]
pub fn solve_p4() {
    const LOWER: u64 = 100;
    const UPPER: u64 = 1000;

    let start = Instant::now();
    let answer = find_largest_pal(LOWER, UPPER);
    let duration = start.elapsed();

    println!("{answer}");
    stopwatch(duration);
}
