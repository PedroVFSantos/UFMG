fun max(lst: int list) =
    case lst of
        [] => raise Fail "A lista está vazia"
      | [x] => x
      | x :: xs => let
                      val restMax = max xs
                  in
                      if x > restMax then x else restMax
                  end;

