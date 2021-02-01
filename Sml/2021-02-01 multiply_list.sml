(* June 2019 exam *)

fun f (l) =
    case l of
        [] => [] |
        a::b => if a >= 0
                then (a*a-1)::f(b)
                else (a*a+1)::f(b)

val ret = f [~1,2,3,0,~5,6]