def mistery(n):
    k = 2
    while((k*k <= n) and (n % k > 0)):
        k = k+1
    return (k*k > n)


for x in range(1, 100):
    print(str(x) + " " + str(mistery(x)))
