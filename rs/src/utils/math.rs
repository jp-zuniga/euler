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

#[allow(non_snake_case)]
#[inline]
pub fn nCr(n: u64, mut r: u64) -> u64 {
    if r > n {
        return 0;
    }

    if r > (n / 2) {
        r = n - r;
    }

    r += 1;

    let mut ways: u64 = 1;

    for i in 1..r {
        ways *= n - i + 1;
        ways /= i;
    }

    ways
}
