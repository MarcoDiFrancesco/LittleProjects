x # to print or print(x)
x <- 5 # assegnazione
x <- c(1,1,1) # vector
length(x) # length of the vector
is.vector(x) # true or false
is.matrix(c)
X <- matrix(1:12,nrow=2,byrow=TRUE)
NROW(X)
NCOL(X)
nrow(X) # not the same of NROW
# y <- X%*%x
is.matrix(y)
dim(y)
drop(y)
z <- drop(y)
X[1,1] # to print first row first col
X[1,] # to print first row
X[,1] # to print first col
X[1,2:5] # first row and from second to fifth col

a <- list(x=x, X=X)
str(a) # see structure
length(a) # gives how many element are in the list

d <- data.frame(x=x, y=1:6)
d <- data.frame(x=x, y=1:6, z=rep(TRUE, 6))
