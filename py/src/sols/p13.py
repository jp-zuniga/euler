# https://projecteuler.net/problem=13
# --------------------------------------------------------------------------------------
# Find the first 10 digits of the sum of all the 50-digit numbers.

from __future__ import annotations

from src.utils import parse_file
from src.utils.files import PROBLEM_13


def solve() -> None:
    big_sum: int = 0
    big_nums: list[int] = [int(x) for x in parse_file(PROBLEM_13, ",")]

    for num in big_nums:
        big_sum += num

    print(
        f"First 10 digits of the sum of all given 50-digit numbers: {str(big_sum)[:10]}"
    )
