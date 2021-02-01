fun f filename =
    let
        val file = TextIO.openIn filename
        val str = TextIO.inputAll file
        val rec elem_pari = fn [] => []
        | a::[] => []
        | a::b::c => Char.toString(b)::(elem_pari c)
    in
        TextIO.closeIn file;
        elem_pari (explode str)
    end;
val res = f "input.txt";


fun f1 (filename) =
    let
        (* Open file *)
        val file = TextIO.openIn filename
        val str = TextIO.inputAll file
        fun read_file(l) =
            case l of
                [] => [] |
                _::a => [] |
                a::b::c => b::read_file(c)
    in
        TextIO.closeIn file;
        read_file (explode str)
    end
val ret = f1 "input.txt"

fun f2 (filename) =
    let
        (* Open file *)
        val file = TextIO.openIn filename
        val str = TextIO.inputAll file
        fun read_file (l) = 
            case l of
                [] => [] |
                _::[] => [] |
                a::b::c => Char.toString(b)::read_file(c)
    in
        TextIO.closeIn file;
        read_file (explode str)
    end
val ret = f2 "input.txt"

fun f3 (filename) = 
    let
        val file = TextIO.openIn filename
        val my_string = TextIO.inputAll file
        fun read_file (string) = 
            case string of
                [] => [] |
                a::b => if Char.toString(a) = " "
                        then read_file(b)
                        else a::read_file(b)
    in
        TextIO.closeIn file;
        read_file (explode my_string)
    end
val res_sett_2019 = f3 "input.txt"