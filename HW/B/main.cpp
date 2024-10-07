/*******************************************
Niktia Klepikovs, nk24033
B17. Dots naturāls skaitlis n. Atrast tos pirmskaitļus, kuri mazāki par n un kurus var izteikt formā 2^k -1. Risinājumā izmantot funkciju, kas atpazīst pirmskaitli.
Programma izveidota: 04.10.2024.
*******************************************/

#include <iostream>
#include <cmath>
#include <vector>
#include <functional>

/**
 * bool isPrime(int n)
 * @brief Pārbauda vai skaitlis ir pirmskaitlis
 * @param n Skaitlis, kuru jāpārbauda
 * @return Vai skaitlis ir pirmskaitlis
 */
bool isPrime(int n)
{
    // Ja skaitlis ir mazāks vai vienāds ar 1, tad tas nav pirmskaitlis
    if (n <= 1)
    {
        return false;
    }

    // Pārbauda vai skaitlis dalās ar kādu citu skaitli, kas nav 1 un n 
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0) // Ja skaitlis dalās ar kādu citu skaitli, tad tas nav pirmskaitlis
        {
            return false;
        }
    }

    return true;
}

/**
 * std::vector<int> findPrimes(int n)
 * @brief Atrod pirmskaitļus, kuri mazāki par n un kuriem izteikts ir 2^k -1
 * @param n Skaitlis, līdz kuram meklē pirmskaitļus
 * @return Pirmskaitļi, kuri mazāki par n un kuriem izteikts ir 2^k -1
 */
std::vector<int> findPrimes(int n)
{
    std::vector<int> primes;

    // Pārbauda katru naturalo skaitli no 1 līdz n
    for (int i = 1; i < n; i++)
    {
        if (isPrime(i))
        {
            // Iziet cauri visiem skaitļiem no 1 līdz i un pārbauda vai kāds no tiem ir 2^k -1
            for (int k = 1; k < i; k++)
            {
                if (std::pow(2, k) - 1 == i)
                {
                    primes.push_back(i); // Ja skaitlis ir 2^k -1, tad pievieno to pie pirmskaitļu masīva
                }
            }
        }
    }

    return primes;
}


int main()
{
    int ok = 0;
    do
    {
        // Skaitla ievade no lietotaja
        int n;
        std::cout << "Ievadiet skaitli n: ";
        std::cin >> n;

        // Parbaude vai  skaitlis n ir naturals
        if (n <= 0)
        {
            std::cout << "Ievadits skaitlis nav naturals" << std::endl;
            continue;
        }

        // Atrast pirmskaitļus, kuri mazāki par n un kurus var izteikt formā 2^k -1
        std::vector<int> primes = findPrimes(n);
        if (primes.size() == 0) // Ja massivs ir tukss tad nav tadu pirmskaitļu kuri izteikti ir 2^k -1
        {
            std::cout << "Nav pirmskaitlu, kuri mazaki par " << n << " un kuri var izteikt forma 2^k -1" << std::endl;
        }
        else
        {
            std::cout << "Pirmskaitli, kuri mazaki par " << n << " un kuri var izteikt forma 2^k -1: ";
            for (int i = 0; i < primes.size(); i++) // Izvada visus pirmskaitļus, kuri izteikti ir 2^k -1
            {
                std::cout << primes[i] << " ";
            }
            std::cout << std::endl;
        }


        // Turpinat vai beigt
        std::cout << std::endl
                  << "Vai turpinat (1) vai beigt (0)? ";
        std::cin >> ok;
    } while (ok == 1);

    return 0;
}

/**************Testa plāns************
n       Rezultāts
5       3
8       3, 7
33      3, 7, 31
89      3, 7, 31
4999	3, 7, 31, 127
0       Nav naturāls skaitlis
-5      Nav naturāls skaitlis
*******************************************/