# website that helps
# http://host.uniroma3.it/docenti/mortera/statisticaNNO/stim.html

n1 <- 7 # all
n2 <- function(lambda) { ifelse(lambda>0, (5/24)*1/(lambda^2), 0) }
n3 <- 3
n4 <- 10/sum(c(1.90,0.40,0.60,0.10,0.50,0.20,1.70,0.10,0.50,0.30))
n2izzo <- function(lambda) { ifelse(lambda>0, ((1/lambda)^2+(2/lambda)^2)/3^2, 0) }

print(n1)
print(n2(2))
print(n3)
print(n4)
print(n2izzo(1))