lx <- 5
ly <- 4
lz <- lx + ly

prX <- function(n) { exp(-lx)*lx^n/factorial(n) }
prY <- function(n) { exp(-ly)*ly^n/factorial(n) }
prZ <- function(n) { exp(-lz)*lz^n/factorial(n) }

n1 <- 5
n2 <- prX(8)*prY(2)/prZ(10)

prXZ <- function(n){
  prX(n)*prY(10-n)/prZ(10)
}

EXZ <- function(n) {
  prXZ(n)*n
}

print(n1)
print(n2)
print(sum(EXZ(0:10)))
