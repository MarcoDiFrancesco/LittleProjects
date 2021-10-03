fun pow(n:int, times:int) = 
    if times <= 0
    then 1
    else n * pow(n, times - 1)

val x = pow(2, 3)

fun my_case (suit, rank) =
  case rank of
      "Ace" => 14
    | "King" => 13
    | "Queen" => 12
    | "Jack" => 11
    | "Num" => 12
val my_case_res = my_case("my_suit", "King")