from __future__ import annotations

from typing import TYPE_CHECKING

from . import files
from .alph_pos import get_alph_pos
from .parse import parse_file
from .performance import stopwatch

if TYPE_CHECKING:
    from collections.abc import Callable


def exec_sol(func: Callable) -> None:
    print(f"Execution time: {stopwatch(func):.6f}ms")


__all__: list[str] = [
    "exec_sol",
    "files",
    "get_alph_pos",
    "parse_file",
]
