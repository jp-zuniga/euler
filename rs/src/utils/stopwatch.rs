use std::time::Duration;

pub fn print_time(duration: Duration) {
    println!("Execution time: {:.6}ms", duration.as_secs_f64() * 1000.0);
}
