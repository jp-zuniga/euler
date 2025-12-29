# Problem URL: https://projecteuler.net/problem=42
# -------------------------------------------------------------------------------
# Formula for nth triangle number: (n * (n+1)) / 2
# Word value: sum of each letter's position in the alphabet.
# Triangle words: words whose value is a triangle number.
# -------------------------------------------------------------------------------
# Find how many words in the given file are "triangle" words.

# ! optimize < 1ms

from __future__ import annotations

from src.utils import get_alph_pos, parse_file
from src.utils.files import PROBLEM_42


def solve() -> None:
    # read the file and save each word in it into a list
    words: list[str] = parse_file(PROBLEM_42, ",")

    # precalculate the first 1000 triangle numbers
    triangle_nums: set[int] = {int((0.5 * n) * (n + 1)) for n in range(1, 1001)}

    triangle_words: int = 0

    for word in words:
        value: int = 0

        for letter in word.strip('"'):
            value += get_alph_pos(letter)

        if value in triangle_nums:
            triangle_words += 1

    print(f"Triangle word count: {triangle_words}")
