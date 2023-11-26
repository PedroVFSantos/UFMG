fun split(lst: int list) =
    let
        fun splitHelper([], odds, evens) = (rev odds, rev evens)
          | splitHelper(x::xs, odds, evens) =
            if x mod 2 = 1 then
                splitHelper(xs, x::odds, evens)
            else
                splitHelper(xs, odds, x::evens)
    in
        splitHelper(lst, [], [])
    end;

