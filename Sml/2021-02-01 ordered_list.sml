fun f [] = true |
    f (_::[]) = true |
    f (a::b::e) = if a > b then false else f (b::e)

val res_true = f [1, 2, 3, 4]
val res_false = f [1, 3, 2, 4]
