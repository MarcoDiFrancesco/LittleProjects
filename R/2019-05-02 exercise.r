n1 <- 1-exp(-5.2/7)
n2 <- -log(0.89)*7
n3 <- 1-exp(-8.7/7)-(1-exp(-6.7/7))
n4 <- function(u) {1/7*exp(-u/7)}
print(n1)
print(n2)
print(n3)
print(n4(1))