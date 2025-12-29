from __future__ import annotations

from time import perf_counter
from typing import TYPE_CHECKING

if TYPE_CHECKING:
    from collections.abc import Callable


def stopwatch(func: Callable) -> float:
    start: float = perf_counter()
    func()
    end: float = perf_counter()

    # convert to milliseconds
    return (end - start) * 1000
