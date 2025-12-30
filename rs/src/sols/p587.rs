// https://projecteuler.net/problem=587
// -------------------------------------------------------------------------------------

use std::f64::consts::PI;
use std::time::Instant;

use crate::utils::print_time;

// #[inline]
// fn circle(x: f64) -> f64 {
//     1.0 - (1.0 - (x - 1.0).powi(2)).sqrt()
// }

#[inline]
fn integral(x: f64) -> f64 {
    let offset = x - 1.0;

    x - 0.5 * (offset.asin() + offset * (1.0 - offset * offset).sqrt())
}

#[inline]
fn integrate(a: f64, b: f64) -> f64 {
    integral(b) - integral(a)
}

#[inline]
fn intersect(m: f64) -> f64 {
    (m + 1.0 - (2.0 * m).sqrt()) / ((m * m) + 1.0)
}

pub fn solve_p587() {
    const B: f64 = 1.0;
    const L_SECTION: f64 = (4.0 - PI) / 4.0;
    const TARGET: f64 = L_SECTION * 0.001;

    let start = Instant::now();

    let mut n = 15;

    loop {
        let m = 1.0 / n as f64;
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
    print_time(duration);
}
