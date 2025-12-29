from __future__ import annotations


def get_alph_pos(letter: str) -> int:
    if not letter.isalpha() or len(letter) != 1:
        msg = "Expected a single alphabetical character."
        raise ValueError(msg)

    return ord(letter.upper()) - ord("A") + 1
