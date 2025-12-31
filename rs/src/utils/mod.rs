use std::time::Duration;

pub mod math;
pub mod primes;

#[inline]
pub fn stopwatch(duration: Duration) {
    println!("Execution time: {:.6}ms", duration.as_secs_f64() * 1000.0);
}
