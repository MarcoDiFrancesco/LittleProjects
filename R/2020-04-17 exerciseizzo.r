f1 <- function(x) {2*1.13*x*exp(-1.13*x^2)}
f3a <- function(x) {0.71*x*exp(-0.71*x)}
f3b <- function(x) {0.71*x^2*exp(-0.71*x)}
n1 <- integrate(f1,0,0.66)
n2 <- integrate(f1,0.65,1.67)
n3a <- integrate(f3a,0,+Inf)
n3b <-integrate(f3b,0,+Inf)
print(n1,digits=22)
print(n2,digits=22)
print(n3a,digits=22)
print(n3b,digits=22)