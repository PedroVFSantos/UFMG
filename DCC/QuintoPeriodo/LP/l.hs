import System.Random

main :: IO ()
main = do
    putStrLn "Bem-vindo ao jogo de adivinhação!"
    putStrLn "Estou pensando em um número entre 1 e 100. Tente adivinhar."

    -- Gere um número aleatório entre 1 e 100
    numberToGuess <- randomRIO (1, 100)

    -- Inicie o loop de adivinhação
    guessLoop numberToGuess 1

-- Função recursiva para o loop de adivinhação
guessLoop :: Int -> Int -> IO ()
guessLoop numberToGuess attempt = do
    putStrLn "Digite sua tentativa:"
    guessStr <- getLine

    -- Converta a entrada do usuário para um número
    let guess = read guessStr :: Int

    -- Compare a tentativa com o número gerado aleatoriamente
    case compare guess numberToGuess of
        LT -> do
            putStrLn "Tente um número maior."
            guessLoop numberToGuess (attempt + 1)
        GT -> do
            putStrLn "Tente um número menor."
            guessLoop numberToGuess (attempt + 1)
        EQ -> do
            putStrLn $ "Parabéns! Você acertou em " ++ show attempt ++ " tentativas."

