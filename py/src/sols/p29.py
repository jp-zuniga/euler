# https://projecteuler.net/problem=29
# -------------------------------------------------------------------------------
# Find the number of distinct terms produced by a^b,
# where 2 <= a <= 100 and 2 <= b <= 100.

# optimize < 1ms

from __future__ import annotations


def solve() -> None:
    distinct: set[int] = set()

    # disgusting brute force approach
    for a in range(2, 101):
        for b in range(2, 101):
            distinct.add(a**b)

    print(f"Number of distinct terms found: {len(distinct)}")
