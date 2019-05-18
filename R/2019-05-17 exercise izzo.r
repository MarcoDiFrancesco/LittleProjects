# pexp(x,lambda) distribution function
# dexp(x,lambda) probability function


n1 <- function(u) { ifelse(u>0.841181,dexp(u,1.4),dexp(u,1)) }
n2 <- pexp(1.0181,0.6)-pexp(0.36,0.6)+(1-pexp(1.0181,1.5))

print(n1(0))
print(n2) # n2 and n3
