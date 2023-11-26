fun pow(n: int, e: int) =
    if e = 0 then 1
    else if e > 0 then n * pow(n, e - 1)
    else raise Fail "Sem suporte a expontes negativos";

