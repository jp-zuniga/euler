# https://projecteuler.net/problem=20
# --------------------------------------------------------------------------------------
# Find the sum of the digits in 100!

from __future__ import annotations

from math import factorial


def solve() -> None:
    sum_digits: int = 0
    fact: int = factorial(100)

    for digit in str(fact):
        sum_digits += int(digit)

    print(f"Sum of the digits in `100!`: {sum_digits}")
