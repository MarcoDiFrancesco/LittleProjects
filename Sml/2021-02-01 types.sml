type int_list_type = int list
fun is_empty(x: int_list_type) =
    if null(x)
    then true
    else false
val is_empty_true = is_empty([])
val is_empty_false = is_empty([1, 2, 3])

datatype int_or_nil = Nil | Int of int;
type ambiente = string -> int_or_nil
val ambientevuoto = fn _:string => Nil;
