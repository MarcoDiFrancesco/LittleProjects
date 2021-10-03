fun conta(l) =
    case l of
        [] => 0 |
        f::e => 
            if List.exists(fn y => y = f) e
            then conta (e)
            else conta (e) + 1

val res11 = conta (["pera", "pera", "pera", "aa", "aa", "gigi"])
val res12 = conta [1,2,4,5,6,0,1,4,5];

fun conta2 (l) =
    case l of
        [] => 0 |
        a::[] => 1 |
        a::b => if List.exists(fn y => y = a) b
                then conta2(b)
                else conta2(b) + 1


val res21 = conta2(["a", "a", "b", "c"])
val res22 = conta2 [1,2,4,5,6,0,1,4,5];