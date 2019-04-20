mean <- 29.5 # mu
variance <- 41.6025 # sigma^2
sd <- sqrt(variance) # sigma

n1 <- (33.757-mean)/sd
print(n1,digits=22)

n2 <- pnorm(33.757, mean, sd)
print(n2,digits=22)

n3 <- 1 - pnorm(39.949, mean, sd)
print(n3,digits=22)
