"""
Computation test
"""

import time


def compute():
    """
    Make 10.000.000 cycles
    """
    number = 0
    start_time = time.time()
    for _ in range(0, 10000000):
        number = number + 1
        number = number - 1
    time_difference = time.time() - start_time
    print("--- ", time_difference, " seconds ---")


if __name__ == "__main__":
    compute()
