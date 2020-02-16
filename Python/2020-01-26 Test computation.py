import time


def compute():
    """
    Make 10.000.000 cycles
    """
    number = 0
    start_time = time.time()

    for iterator in range(0, 100000000):
        number = number+1
        number = number-1

    print("--- %s seconds ---" % (time.time() - start_time))


if __name__ == "__main__":
    compute()
