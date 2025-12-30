use std::time::Duration;

mod math;
mod primes;

pub use math::lcm;
pub use primes::{is_prime, prime_factors, prime_sieve};

#[inline]
pub fn stopwatch(duration: Duration) {
    println!("Execution time: {:.6}ms", duration.as_secs_f64() * 1000.0);
}
