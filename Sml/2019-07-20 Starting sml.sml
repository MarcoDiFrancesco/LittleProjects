(* values and negative values *)
val a = 4.0;
val b = ~3.0;
val mul = a * b;

(* if statements *)
if a >= b then a else b;
val a:bool = false;

(* functions *)
val increment = fn n => n + 1;
increment 5;

(* another way to write a function*)
fun increment2(n) = n + 1;
increment2(6);

val day = fn n => case n of
             1 => "Monday"
           | 2 => "Tuesday"
           | 3 => "Wednesday"
           | _ => "Day_not_valid";
day(2);

fun day2(n) = case n of
                   1 => "Monday"
                 | 2 => "Tuesday"
                 | 3 => "Wednesday"
                 | _ => "Day_not_valid";
day2(3);

val day3 = fn 1 => "Monday"
            | 2 => "Tuesday"
            | 3 => "Wednesday"
            | _ => "Day_not_valid";
day3(3);

(* function with 2 variables *)
fun sum(a, b) = a+b;
sum(5,6);

(* to write values on variables *)
val (x, y) = (4, 5);

(* recursive functions *)
val rec fact = fn n => if n = 0 then 1 else n * fact(n-1);
fact(5);
(* fun had already the recursion *)
fun fact2(n) = if n = 0 then 1 else n * fact2(n - 1);
fact2(5);

val fact3 = fn n =>
	let
		val rec fact_tr = fn n => fn res =>
			if n = 0 then
				res
			else
				fact_tr(n - 1) (n * res)
	in
		fact_tr n 1
	end;
fact3(5);