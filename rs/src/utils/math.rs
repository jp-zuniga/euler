#[inline]
const fn gcd(mut a: u64, mut b: u64) -> u64 {
    while b != 0 {
        (a, b) = (b, a % b);
    }

    a
}

#[inline]
pub const fn lcm(a: u64, b: u64) -> u64 {
    (a / gcd(a, b)) * b
}
