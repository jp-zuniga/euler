# https://projecteuler.net/problem=16
# -------------------------------------------------------------------------------
# Find the sum of the digits of 2^1000.

from __future__ import annotations


def solve() -> None:
    big_num: int = 2**1000
    digit_sum: int = 0

    num_string = str(big_num)

    for digit in num_string:
        digit_sum += int(digit)

    print(f"Sum of the digits of `2^1000`: {digit_sum}")
