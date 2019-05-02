mean <- 5.33 # mu
sd <- 0.47 # sigma
variance <- sd^2 # sigma^2

n1 <- 1 - pnorm(5.9903836, mean, sd)
print(n1,digits=22)

excusionProb <- pnorm(4.6998451, mean, sd) + 1 - pnorm(5.9903836, mean, sd)
# f=1/T -> T=1/f
n2 <- 1/excusionProb
print(n2,digits=22)

n3 <- (4.6998451-5.33)/0.47
print(n3,digits=22)

n4 <- pnorm(4.6998451, mean, sd)
n5 <- pnorm(5.9903836, mean, sd)
print(n4,digits=22)
print(n5,digits=22)