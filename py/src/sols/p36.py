# Problem URL: https://projecteuler.net/problem=36
# -------------------------------------------------------------------------------
# Find the sum of all numbers, under 1 million,
# which are palindromic in base 10 *and* base 2.

# ! optimize < 10ms

from __future__ import annotations


def solve() -> None:
    sum_pals: int = 0

    for i in range(10**6):
        str_num = str(i)

        if str_num == reversed(str_num):
            bin_num = f"{i:b}"

            if bin_num == reversed(bin_num):
                # found double palindrome
                sum_pals += i

    print(f"Sum of all double palindromes under 1 million: {sum_pals}")
