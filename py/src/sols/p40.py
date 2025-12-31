# https://projecteuler.net/problem=40
# --------------------------------------------------------------------------------------
# An irrational decimal fraction is created by concatenating the positive integers:
# 0.123456789101112131415161718192021...
# --------------------------------------------------------------------------------------
# Find the product of the first, tenth, hundredth, thousandth,
# ten-thousandth, hundred-thousandth, and millionth digit of this fraction.

# optimize < 10ms

from __future__ import annotations


def solve() -> None:
    # concatenate the first million positive integers
    frac_part: str = "".join(str(i) for i in range(1, (10**6 + 1)))
    product: int = 1

    # use powers of 10 to access the desired digits
    for i in range(7):
        product *= int(frac_part[10**i - 1])

    print(f"Digit product: {product}")
