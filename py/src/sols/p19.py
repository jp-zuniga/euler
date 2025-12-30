# https://projecteuler.net/problem=19
# -------------------------------------------------------------------------------
# How many Sundays fell on the first of the month during the 20th century?

# optimize < 5ms

from __future__ import annotations

from datetime import date, timedelta

FIRST_OF_THE_MONTH = 1
SUNDAY = 6


def solve() -> None:
    sunday_count: int = 0

    current = date(1901, 1, 1)
    end = date(2000, 12, 31)

    while current != end:
        if current.day == FIRST_OF_THE_MONTH and current.weekday() == SUNDAY:
            sunday_count += 1

        current += timedelta(1)

    print(
        f"{sunday_count} Sundays fell on the first of the month during the 20th century"
    )
