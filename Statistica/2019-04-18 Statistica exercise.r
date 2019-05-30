# the answer is k
k <- 1000/11191
n1 <- integrate(function(x) {(k*(6.71-2*x))},0,3.1) # needs to be 1
# print(n1$value,digits=22)
print(k)

n2 <- integrate(function(x) {(x*1000/11191*(6.71-2*x))},0,3.1)
print(n2$value,digits=22)

n3 <- 13.6-1.1*n2$value
print(n3,digits=22)

# variance
n4a <- integrate(function(x) {(x^2*1000/11191*(6.71-2*x))},0,3.1)
n4b <- integrate(function(x) {(x*1000/11191*(6.71-2*x))},0,3.1)
n4 <- n4a$value-(n4b$value)^2
print(n4,digits=22)
