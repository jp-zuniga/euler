// https://projecteuler.net/problem=587
// -------------------------------------------------------------------------------------
// A square is drawn around a circle. We shall call the blue region the L-section.
// A line is drawn from the bottom left of the square to the top right.
// We shall call the orange region a concave triangle.
// -------------------------------------------------------------------------------------
// What is the least value of n for which the concave triangle
// occupies less than 0.1% of the L-section?

use std::f64::consts::PI;
use std::time::Instant;

use crate::utils::stopwatch;

#[allow(clippy::suboptimal_flops)]
#[inline]
fn integral(x: f64) -> f64 {
    let offset = x - 1.0;

    x - 0.5 * (offset.asin() + offset * (1.0 - offset * offset).sqrt())
}

#[inline]
fn integrate(a: f64, b: f64) -> f64 {
    integral(b) - integral(a)
}

#[allow(clippy::suboptimal_flops)]
#[inline]
fn intersect(m: f64) -> f64 {
    (m + 1.0 - (2.0 * m).sqrt()) / ((m * m) + 1.0)
}

#[allow(clippy::suboptimal_flops)]
#[inline]
pub fn solve_p587() {
    const B: f64 = 1.0;
    const L_SECTION: f64 = (4.0 - PI) / 4.0;
    const TARGET: f64 = L_SECTION * 0.001;

    let start = Instant::now();

    let mut n = 15;

    loop {
        let m = 1.0 / f64::from(n);
        let cm = intersect(m);

        let left_concave = (m * cm * cm) / 2.0;
        let right_concave = integrate(cm, B);

        if (left_concave + right_concave).abs() < TARGET {
            break;
        }

        n += 1;
    }

    let duration = start.elapsed();

    println!("{n}");
    stopwatch(duration);
}
