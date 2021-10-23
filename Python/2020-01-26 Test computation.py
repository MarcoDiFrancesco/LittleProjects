"""
Computation test
"""

from time import time


def compute(n: int) -> None:
    """
    Make 10.000.000 cycles
    """
    start_time = time()
    for _ in range(n):
        ...

    print(f"--- {time() - start_time} seconds ---")


if __name__ == "__main__":
    compute(10000000)
