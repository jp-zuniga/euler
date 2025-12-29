# Problem URL: https://projecteuler.net/problem=48
# -------------------------------------------------------------------------------
# Find the last 10 digits of the self powers series:
# 1^1 + 2^2 + 3^3 + ... + 1000^1000

# ! optimize < 5ms

from __future__ import annotations


def solve() -> None:
    series: int = 0
    for i in range(1, 1001):
        series += i**i

    print(f"Last 10 digits of the self powers series: {str(series)[-10:]}")
