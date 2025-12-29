from __future__ import annotations

from src import sols
from src.utils import exec_sol


def main() -> None:
    exec_sol(sols.p56.solve)


if __name__ == "__main__":
    main()
