#[inline]
const fn gcd(mut a: i32, mut b: i32) -> i32 {
    while b != 0 {
        (a, b) = (b, a % b);
    }

    a
}

#[inline]
pub const fn lcm(a: i32, b: i32) -> i32 {
    (a / gcd(a, b)) * b
}
