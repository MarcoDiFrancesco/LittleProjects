mean <- 6.3 # mu
sd <- 0.55 # sigma
variance <- sd^2 # sigma^2

n1 <- 1 - pnorm(7.2046695, mean, sd)
print(n1,digits=22)

excusionProb <- pnorm(5.4448745, mean, sd) + 1 - pnorm(7.2046695, mean, sd)
# f=1/T -> T=1/f
n2 <- 1/excusionProb
print(n2,digits=22)

n3 <- (5.4448745-6.3)/0.55
print(n3,digits=22)
