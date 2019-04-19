# the answer is k
n1 <- integrate(function(x) {(1000/15424*(8.02-2*x))},0,3.2)
print(n1$value,digits=22)

n2 <- integrate(function(x) {(x*1000/15424*(8.02-2*x))},0,3.2)
print(n2$value,digits=22)

n3 <- 4.2-0.4*n2$value
print(n3,digits=22)

# variance
n4a <- integrate(function(x) {(x^2*1000/15424*(8.02-2*x))},0,3.2)
n4b <- integrate(function(x) {(x*1000/15424*(8.02-2*x))},0,3.2)
n4 <- n4a$value-(n4b$value)^2
print(n4,digits=22)

