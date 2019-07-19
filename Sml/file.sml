fun move n from to via =
  if n=0 then
    " ; "
  else
    (move (n-1) from via to) ^
    "Move disk from " ^ from ^ " to " ^ to ^
    (move (n-1) via to from);
