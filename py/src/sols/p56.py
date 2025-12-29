# Problem URL: https://projecteuler.net/problem=56
# -------------------------------------------------------------------------------
# For natural numbers a, b < 100, what is the maximum digital sum of a^b?

# !!! optimize < 10ms

from __future__ import annotations


def solve() -> None:
    max_digital_sum = 0

    # disgusting brute force approach
    for a in range(1, 100):
        for b in range(1, 100):
            digit_sum: int = 0

            for digit in str(a**b):
                digit_sum += int(digit)

            max_digital_sum = max(max_digital_sum, digit_sum)

    print(f"Maxmimum digital sum of a^b (for a, b < 100): {max_digital_sum}")
