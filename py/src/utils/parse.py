from __future__ import annotations

from pathlib import Path


def parse_file(file_name: str, split_char: str, strip_char: str = " ") -> list[str]:
    root: Path = Path(__file__).resolve().parents[3]

    file_path: Path = root / "inputs" / file_name

    with file_path.open() as file:
        contents: list[str] = [
            elem.strip(strip_char)
            for line in file.readlines()
            for elem in line.split(sep=split_char)
        ]

    return contents
