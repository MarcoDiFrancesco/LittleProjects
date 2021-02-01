datatype ITER = Iter of int * (int -> int);

(* val rec eval =
    fn Iter (n, f) =>
    fn x =>
        if (n > 0)
        then eval (Iter (n-1, f)) (f x)
        else x; *)

val rec eval =
    fn Iter(n, f) =>
    fn x =>
        if n > 0
        then eval(Iter(n-1, f)) (f x)
        else x

val f = fn x => x * 2
val g = eval(Iter(3, f))
val res = g(5)