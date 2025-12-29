# Problem URL: https://projecteuler.net/problem=22
# -------------------------------------------------------------------------------
# Find the sum of the scores of all the names listed in the given file.
# The names must be in alphabetical order. A name's score is equal to the sum of
# its letters' positions in the alphabet, multiplied by the name's position in the list.

# ! optimize < 5ms

from __future__ import annotations

from src.utils import get_alph_pos, parse_file
from src.utils.files import PROBLEM_22


def solve() -> None:
    sum_scores: int = 0
    names: list[str] = sorted(parse_file(PROBLEM_22, ","))

    for i, name in enumerate(names):
        letter_sum: int = 0

        for letter in name.strip('"'):
            letter_sum += get_alph_pos(letter)

        sum_scores += letter_sum * (i + 1)

    print(f"Sum of all the names' scores: {sum_scores}")
