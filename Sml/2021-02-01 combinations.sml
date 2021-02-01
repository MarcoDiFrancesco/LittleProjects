fun prod (n, m) =
    if n < m
    then n*prod(n+1, m)
    else m

fun comb (n, k) = prod (1, n) div (prod (1, k) * prod (1, n-k))


val res_prod = prod (2, 4)
val res_comb = comb (3, 10)