def is_prime(num):
    if num <= 1:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

def prime_numbers(n):
    primes = []
    num = 2
    while len(primes) < n:
        if is_prime(num):
            primes.append(num)
        num += 1
    return primes

try:
    n = int(input("Digite um número n: "))
    if n <= 0:
        print("Digite um número positivo maior que zero.")
    else:
        prime_list = prime_numbers(n)
        print(f"Os primeiros {n} números primos são: {prime_list}")
except ValueError:
    print("Por favor, digite um número válido.")

