"""
Niktia Klepikovs, nk24033
B17. Dots naturāls skaitlis n. Atrast tos pirmskaitļus, kuri mazāki par n un kurus var izteikt formā 2^k -1. Risinājumā izmantot funkciju, kas atpazīst pirmskaitli.
Programma izveidota: 04.10.2024.
"""

def is_prime(n):
    """
    def is_prime(n):
    Pārbauda vai skaitlis ir pirmskaitlis
    Atgriez vai skaitlis ir pirmskaitlis
    """

    # Ja sk. ir mazāks vai vienāds ar 1, tad tas nav pirmskaitlis
    if n <= 1:
        return False
    
    # Pārbauda vai skaitlis dalās ar kādu citu skaitli, kas nav 1 un n 
    for i in range(2, n):
        if n % i == 0: # Ja skaitlis dalās ar kādu citu skaitli, tad tas nav pirmskaitlis
            return False

    return True

def find_primes(n):
    """
        def find_primes(n):
        Atrod pirmskaitļus, kuri mazāki par n un kuriem izteikts ir 2^k -1
        Atgriez masivu ar pirmskaitļiem, kuri mazāki par n un kuriem izteikts ir 2^k -1
    """
    primes = []
    
    # Pārbauda katru naturalo skaitli no 1 līdz n
    for i in range(1, n):
        if is_prime(i):
            # Iziet cauri visiem skaitļiem no 1 līdz i un pārbauda vai kāds no tiem ir 2^k -1
            for k in range(1, i):
                if pow(2, k) - 1 == i:
                    primes.append(i) # Ja skaitlis ir 2^k -1, tad pievieno to pie pirmskaitļu masīva
    
    return primes

ok = 1
while ok == 1:
    # Skaitla ievade no lietotaja
    n = int(input("Ievadiet skaitli n: "))
    
    # Parbaude vai  skaitlis n ir naturals
    if n <= 0:
        print("Ievadits skaitlis nav naturals")
        continue
    
    # Atrast pirmskaitļus, kuri mazāki par n un kurus var izteikt formā 2^k -1
    primes = find_primes(n)
    
    # Ja massivs ir tukss tad nav tadu pirmskaitļu kuri izteikti ir 2^k -1
    if len(primes) == 0:
        print(f"No primes less than {n} can be expressed as 2^k - 1.")
    else:
        print(f"Primes less than {n} that can be expressed as 2^k - 1: ")
        for prime in primes: # Izvada visus pirmskaitļus, kuri izteikti ir 2^k -1
            print(prime)
    
    # Continue or exit
    ok = int(input("Continue (1) or exit (0)? "))

"""
=========Testa plans:==========
n       Rezultāts
5       3
8       3, 7
33      3, 7, 31
89      3, 7, 31
4999	3, 7, 31, 127
0       Nav naturāls skaitlis
-5      Nav naturāls skaitlis
"""