n1 <- function(u) {
  ifelse(u >= 0, 1 - exp(-2.4 * u), 0)
}

n2 <- function(u) {dexp(2.4,u)}

print(n1(2))
print(n2(2))
