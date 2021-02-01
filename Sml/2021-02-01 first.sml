(* This is a comment *)
val x = 32
(* - does not work, ~ is used *)
val y1 = 0 - 31
val y2 = ~31
val z = (x - y1)
val expression = if z > 0 then 1 else 0
val a = true
val s = 8 < 0
(* Type unit *)
val u = ()
(* Division for integers *)
val d = 1 div 3