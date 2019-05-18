# pexp(x,lambda) distribution function
# dexp(x,lambda) probability function


n1 <- function(u) { ifelse(u>0.841181,dexp(u,1.4),dexp(u,1)) }
n2 <- pexp(0.8187308,1)-pexp(0.665,1)+(1-pexp(0.8187308,1.4))

print(n1(0))
print(n2) # n2 and n3
