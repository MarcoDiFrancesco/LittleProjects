data <- c(91.6,83,74.9,84.2,72.9,78.6,79.2,82.1,77,84)
n1 <- sum(data)/10
variance <- (data-n1)^2
n2 <- sqrt(sum(variance)/9) # stimatore
n3 <- 10/9

print(n1)
print(stimatore)
print(n3)
