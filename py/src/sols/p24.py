# Problem URL: https://projecteuler.net/problem=24
# -------------------------------------------------------------------------------
# Find the millionth lexicographic permutation of the digits 0-9.

# !!! optimize < 50ms

from __future__ import annotations

from itertools import permutations
from typing import TYPE_CHECKING

if TYPE_CHECKING:
    from collections.abc import Iterable, Sequence


def solve() -> None:
    digits: str = "0123456789"
    perm_index = int(1e6 - 1)

    # `permutations()` stores each permutation as a tuple,
    # with each of its characters being a separate tuple element
    string_perms: Sequence[Iterable[str]] = list(permutations(digits))

    # convert tuples to strings, then sort the result
    digit_perms: list[str] = sorted(["".join(chars) for chars in string_perms])

    # last element is millionth lexicographic permutation
    print(
        "Millionth lexicographic permutations of the digits 0-9: "
        + digit_perms[perm_index]
    )
