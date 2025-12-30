use std::time::Duration;

mod math;

pub use math::lcm;

#[inline]
pub fn stopwatch(duration: Duration) {
    println!("Execution time: {:.6}ms", duration.as_secs_f64() * 1000.0);
}
