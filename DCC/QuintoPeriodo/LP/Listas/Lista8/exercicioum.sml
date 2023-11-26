fun ehVazio(A) = null A

fun uniaoConj(A, B) =
    let
        val uniao = List.concat [A, B]
    in
        List.foldr (fn (x, acc) => if List.exists (fn y => y = x) acc then acc else x::acc) [] uniao
    end

fun intersConj(A, B) =
    List.filter (fn x => List.exists (fn y => y = x) B) A

fun diffConj(A, B) =
    List.filter (fn x => not (List.exists (fn y => y = x) B)) A

fun diffSimConj(A, B) =
    let
        val uniao = uniaoConj(A, B)
        val intersecao = intersConj(A, B)
    in
        diffConj(uniao, intersecao)
    end

fun addConj(A, x) =
    if List.exists (fn y => y = x) A then A else x::A

fun remConj(A, x) =
    List.filter (fn y => y <> x) A

fun tamConj(A) = List.length A

fun ehElemConj(A, x) = List.exists (fn y => y = x) A