# Linguaggi di programmazione 1
## Professor Kuper

unitn: single value() used for expression that do not return a value

If statement: if 5<6 then 3 else 5; not possible to do if 5<6 then 3;
val v = 5.0;
val pi = 3.1415
To force types: val v:int = 5;

val it = 1; int is the same of writing 1;

Functions: fn n => n+1;

val sum = fn: int * int -> int 
Function with a single parameter (that is an integer)

val day = fn 1=> "M" | 2 => "T" | _ => "0";
Is a function that has 3 possibilities. To show them: 
day 1;

val x = true: bool;
val x = fn n => 
case exp of true => exp1 | false => exp2;

val whats = fn 1 => "one" | x => "anything else";
Function to return one of val 1; and anything else with any other thing.

val rec fact = fn n => if n=0 then 1 else n*fact (n-1);
With rec you are allowing recursion in the program, without it it throws you an error.
With fact 20; it calculates

