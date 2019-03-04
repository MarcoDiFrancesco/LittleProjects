ps <- function(x,y=1){
z <- x^2+y^2
C <- cos(x)
S <- sin(x)
result <- list()
result$z <- z
result$C <- C
result$S <- S
return(result)
}
ls()
res <- ps(y=rnorm(100),x=rnorm(100))
ls(res)
str(res)
plot(res$z, res$C, xlab="Z", ylab="Y")
hist(res$z) # histogram
boxplot(res$z) # boxplot
with(res, boxplot(z))

x <- rnorm(100)
r <- rep(NA, 100)
for (i in 1:100) {
  if(x[i] < 0) {
    r[i] <- FALSE
  } else {
    r[i] <- TRUE
  }
}
table(r)

alb <- function(x) {
  z <- x^2
  class(z) <- "sam"
  return(z)
}
res <- alb(rnorm(100))
str(res)
print.sam <- function(x, ...) {
  cat("Is this the result?\n")
  print.default(x[1:10], ...)
  invisible(x)
}
print.sam(res)
print(res)