"""
Exercise picture
https://i.imgur.com/Ijp6QEe.png
"""


def domino(n):
    DP = [None] * n
    DP[0] = DP[1] = 1
    for i in range(2, n):
        DP[i] = DP[i - 1] + DP[i - 2]
    return DP


if __name__ == "__main__":
    a = domino(1000000)
    # print(a)
