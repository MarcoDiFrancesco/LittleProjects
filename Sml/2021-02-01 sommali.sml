fun sommali (n, l) =
    case l of
        [] => n |
        _::[] => n |
        _::b::e => sommali(n, e) + b

(* return :13 *)
val ret = sommali (1, [1,2,3,4,5,6])
