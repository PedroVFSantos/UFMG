fun sumLists(list1: int list, list2: int list) =
    if length(list1) <> length(list2) then
        raise Fail "Listas com mesmo tamanho"
    else
        let
            fun sumPairs([], []) = []
              | sumPairs(x::xs, y::ys) = (x + y)::sumPairs(xs, ys)
        in
            sumPairs(list1, list2)
        end;

