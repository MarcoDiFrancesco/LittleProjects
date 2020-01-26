import time

a = 0
start_time = time.time()

for x in range(0, 100000000):
    a = a+1
    a = a-1
print("--- %s seconds ---" % (time.time() - start_time))