# https://projecteuler.net/problem=25
# -------------------------------------------------------------------------------
# Find the index of the first term in the Fibonacci sequence to have 1000 digits.

# optimize < 1ms

from __future__ import annotations

from math import floor, log10

MAX_DIGITS: int = 1000


def solve() -> None:
    # per problem statement, start at 1
    a: int = 1
    b: int = 1
    idx: int = 2

    # keep calculating as long as the newest
    # fibonacci number doesn't have 1000 digits
    while (floor(log10(a)) + 1) < MAX_DIGITS:
        a, b = a + b, a
        idx += 1

    print(
        f"Index of the first term of the Fibonacci sequence to have 1000 digits: {idx}"
    )
