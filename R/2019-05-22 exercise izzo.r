f1 <- function(k) { exp(-9)*9^k/factorial(k) }
n1 <- 1-sum(f1(0:3))
n2 <- sum(f1(0:11))
n3 <- 9

print(n1,digits=22)
print(n2,digits=22)
print(n3)
