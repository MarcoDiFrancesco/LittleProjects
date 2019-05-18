# pexp(x,lambda) distribution function
# dexp(x,lambda) probability function

lx <- 1 # lambda X
ly <- 1.4 # lambda Y
lu <- lx + ly

# F(X) function
fx <- function(x) { lx*exp(-lx*x) }

# F(Y) function
fy <- function(x) { ly*exp(-ly*x) }

# F(U) function
fu <- function(u) { dexp(u,lu) } # the same of { ifelse(x<0, 0, lu*exp(-lu*x)) }

n2 <- integrate(fu, 0.349, +Inf)$value * integrate(fx, 0.665, +Inf)$value
n3 <- integrate(fu, 0.665, +Inf)$value * integrate(fx, 0.349, +Inf)$value

print(n2)
print(n3)

print(exp(-2.4*0.349)*exp(-1*0.665))
fu2 <- 
n <- 0
print(fu(n))
print(fu2(n))
