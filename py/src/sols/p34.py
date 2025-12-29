# Problem URL: https://projecteuler.net/problem=34
# -------------------------------------------------------------------------------
# Find the sum of all the numbers that are equal
# to the sum of the factorial of their digits.

# !!! optimize < 100ms

from __future__ import annotations

from math import factorial


def find_search_limit() -> int:
    # for a number with n digits:
    # - max digit factorial: 9!
    # - max digit factorial sum: 9! * n
    # - max value of an n-digit number: 10^n
    # find the point at which 10^n > (9! * n)

    n: int = 1

    while (factorial(9) * n) >= 10 ** (n - 1):
        n += 1

    return factorial(9) * (n - 1)


def solve() -> None:
    limit: int = find_search_limit()
    num_sum: int = 0

    # per problem statement, start at 3
    for num in range(3, limit):
        sum_digits: int = 0

        for digit in str(num):
            sum_digits += factorial(int(digit))

        if sum_digits == num:
            num_sum += num

    print(
        "Sum of all the numbers that are equal to "
        f"the sum of the factorial of their digits: {num_sum}"
    )
