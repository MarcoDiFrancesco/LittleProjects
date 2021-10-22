def mistery(n: int) -> int:
    k = 2
    while (k*k <= n) and (n % k > 0):
        k += 1

    return k*k > n


for x in range(1, 100):
    print(x, mistery(x))
