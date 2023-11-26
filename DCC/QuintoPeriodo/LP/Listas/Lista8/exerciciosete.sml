fun allTrue(lst: bool list) =
    case lst of
        [] => true (* Se a lista estiver vazia, todos os elementos são verdadeiros por definição. *)
      | x :: xs => x andalso allTrue(xs);

