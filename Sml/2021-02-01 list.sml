val a = []
val b = [1, 2, 3]
(* Cons operator: add at the beginning of the list *)
val concat = 4::5::b
val list_of_list = [[0,1], [2,3], [4,5]]
(* It can't be of tuples like [true, false] *)
val res = [6,7]::list_of_list

val values = [1, 2, 3]
(* returns: 1 *)
val my_head = hd(values)
(* returns: [2, 3] *)
val my_tail = tl(values)
(* returns: true *)
val is_empty_true = null([])
(* returns: false *)
val is_empty_false = null(values)

fun sum_list(values : int list) = 
    if null(values)
    then 0
    else hd(values) + sum_list(tl(values))
val sum_list_ret = sum_list([1,2,3])

fun countdown(value : int) =
    if value = 0
    then []
    else value::countdown(value-1)
val countdown_res = countdown(5);

fun append(xs: int list, ys: int list) =
    if null(xs)
    then ys
    else append(tl(xs), hd(xs)::ys)
val append_res = append([1,2,3], [4,5,6])

fun sum_pair_list(values : (int * int) list) =
    if null(values)
    then 0
    else #1 (hd(values)) + #2 (hd(values)) + sum_pair_list(tl(values))
val sum_pair_list_res = sum_pair_list([(1,2), (3,4), (5,6)])

fun firsts(values: (int * int) list) =
    if null(values)
    then []
    else #1 (hd(values))::firsts(tl(values))
(* returns [1, 3] *)
val firsts_res = firsts([(1, 2), (3, 4)])
