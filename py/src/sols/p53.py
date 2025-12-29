# Problem URL: https://projecteuler.net/problem=53
# -------------------------------------------------------------------------------
# In combinatorics, nCr ("from n choose r") = n! / (r! * (n-r)!), where r <= n.
# -------------------------------------------------------------------------------
# For 1 <= n <= 100, how many values of nCr are greater than 1,000,000?

# ! optimize < 5ms

from __future__ import annotations

from math import factorial


def nCr(n: int, r: int) -> float:  # noqa: N802
    return factorial(n) / (factorial(r) * factorial(n - r))


def solve() -> None:
    total: int = 0

    # disgusting brute force approach
    for n in range(1, 101):
        for r in range(1, n + 1):
            if nCr(n, r) > 10**6:
                total += 1

    print(f"Values of nCr over 1 million: {total}")
