(* Tuples in function *)
fun swap(a : int*bool) =
    if (#2 a) = true
    then (~(#1 a), true)
    else (#1 a, false) 
(* Call function assigning to value *)
val a = swap(1, true);
val b = swap(1, false);
(* Can also pass tuple to function *)
val x = (1, true)
val aa = swap x
(* Tuples of multiple elements *)
val multiple_elements = (1, 2, true)
(* Tuples of tuples *)
val zz = ((1, 1), (2, 2), (3, 3))
val nz = #1 (#1 zz)
