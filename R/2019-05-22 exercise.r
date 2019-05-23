n1 <- FALSE

f2 <- function(n) { 1/2^n*1/2^(10-n)*choose(10,n)}
n2 <- sum(t2(8:10))
# on wolfram n2 <- 7/128

n3 <- choose(10,8)

f4 <- function(n) { 0.45^n*0.55^(10-n)*choose(10,n)}
expectedValue = 0
for(n in 0:10){
  expectedValue = expectedValue + f4(n) * n
}

print(n1)
print(n2)
print(n3)
print(expectedValue) # n4
