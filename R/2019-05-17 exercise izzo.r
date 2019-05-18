# pexp(x,lambda) distribution function
# dexp(x,lambda) probability function

lx <- 0.6 # lambda X
ly <- 1.5 # lambda Y
lu <- lx + ly

# F(X) function
fx <- function(x) { lx*exp(-lx*x) }

# F(Y) function
fy <- function(x) { ly*exp(-ly*x) }

# F(U) function
fu <- function(x) { ifelse(x>0, lu*exp(-lu*x), 0) }

n2 <- integrate(fu, 0.262, +Inf)$value * integrate(fx, 0.36, +Inf)$value
n3 <- integrate(fu, 0.36, +Inf)$value * integrate(fx, 0.262, +Inf)$value

print(n2)
print(n3)
