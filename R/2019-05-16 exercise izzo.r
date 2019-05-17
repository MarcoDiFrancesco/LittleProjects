lx <- 7
ly <- 8
lz <- lx + ly

prX <- function(n) { exp(-lx)*lx^n/factorial(n) }
prY <- function(n) { exp(-ly)*ly^n/factorial(n) }
prZ <- function(n) { exp(-lz)*lz^n/factorial(n) }

n1 <- 5
n2 <- prX(18)*prY(2)/prZ(20)

prXZ <- function(n){
  prX(n)*prY(20-n)/prZ(20)
}

EXZ <- function(n) {
  prXZ(n)*n
}

print(n1)
print(n2)
print(sum(EXZ(0:20)))
