# Statistica exercises
All the exerercises I've done in the third semester of university in the statistica course.

The exercises are ordered by date, some of them contains the part of the exercise of Izzo. Most of the exercises are made in R and some of them in XLSX to make easier my life.

# R notes
Following the [R manual](https://cran.r-project.org/doc/manuals/R-intro.html).  
For a point and click interface you need to use `Rcmdr package`.
## Coding
To get help `help(solve)` or `?solve` or `help("[[")`, with the brakets to make it understanding that the brackets are not used as brackets. Help is also available in HTML version with `help.start()`.  
The double quote marks `"` are more used that the single one.  
`q()` to quit an R session.  
`objects()` or `ls()` to get objects present in memory.
`rm(r)` after `r <- 5` removes the object `r`.

`x <- c(1,2,3)` is a function to assign values to a vector.
`y <- c(x, 5, x);` copies the vector `x` into `y` to create a vector of 7 elemets.
It's possible to devide and multiply directly vector, for exaple:
```
x <- c(1.0,2,3);
y <- 2/x

[1] 2.0000000 1.0000000 0.6666667
```
In addition to normal operators (`+ - * /`) are available:
* `log(numer, base)` or `log(number)` for base e.
* `exp()` is e^x, for example `exp(5)` is e^5.
* `sin()`
* `cos()`
* `tan()`
* `sqrt()` can also work with complex numers e.g. `sqrt(-17+0i)`
* `max` and `min()` secect the biggest and smaller number of a vector

`lenght()` is the number of elements present in a vector.  
`mean()` is the average, like `sum(x)/length(x)`.  
`var()` is sample variance (varianza di campionamento).  
`sort()` return the vector sorted, there are also `order()` and `sort.list()` that produce something different.  
`pmin()` and `pmax()` return a vector (of length equal to their longest argument) that contains in each element the largest (and smallest) element in that position in any of the input vectors.  
