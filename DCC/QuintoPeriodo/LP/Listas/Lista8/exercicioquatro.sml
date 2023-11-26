fun search(lst: int list, n: int) =
    case lst of
        [] => false  
      | x :: xs => if x = n then true  
                   else search(xs, n)  
