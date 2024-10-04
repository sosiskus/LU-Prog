/*******************************************
Niktia Klepikovs, nk24033
A10. Doti divi naturāli skaitļi m un n. Noteikt skaitļa m pirmo n ciparu summu. Skaitļa dalīšana ciparos jāveic skaitliski.
Programma izveidota: 18.09.2024.
*******************************************/

#include <algorithm>
#include <iostream>
#include <vector>

/**
 * std::vector<int> extractDigits(long long m)
 * @brief Sadala skaitlu ciparos un atgriež masivu ar tiem
 * @param m Skaitlis kuru jasadala ciparos
 * @return Dinamisks masivs ar cipariem
*/
std::vector<int> extractDigits(long long m)
{
    std::vector<int> digits;

    while (m > 0) // kamer skaitlis ir lielaks par 0
    {
        digits.push_back(m % 10); // izvlikam pedejo ciparu un pievienojam beigas pie masiva
        m /= 10;                  // dalam skaitli ar 10, lai dabutu nakošo ciparu
    }

    for (int i = 0; i < digits.size() / 2; i++) // apgriežam masīvu, lai cipari būtu pareizā secībā
    {
        long long temp = digits[i];
        digits[i] = digits[digits.size() - i - 1];
        digits[digits.size() - i - 1] = temp;
    }

    return digits;
}

int main()
{
    int ok = 0;
    do
    {
        
        // Skaitla ievade no lietotaja
        long long m, n;
        std::cout << "Ievadiet skaitli m: ";
        std::cin >> m;
        std::cout << "Ievadiet skaitli n: ";
        std::cin >> n;

        // Parbaude vai  skaitli (n un m) ir naturali
        if (n <= 0 || m <= 0)
        {
            std::cout << "Ievadits skaitlis nav naturals" << std::endl;
        }
        else
        {

            // Izvlikt visus ciparus no skaitla un ierakstit massiva digitsArray
            std::vector<int> digitsArray = extractDigits(m);

            // Parbaude vai skaitlim m ir n cipari
            if (digitsArray.size() < n)
            {
                std::cout << "Skaitlim " << m << " nav " << n << " ciparu" << std::endl;
            }
            else
            {

                int sum = 0;
                for (int i = 0; i < n; i++) // saskaitam pirmos n ciparus
                {
                    sum += digitsArray[i];
                }

                std::cout << "Pirmo " << n << " ciparu summa skaitlim " << m << " ir " << sum << std::endl;
            }
        }

        // Turpinat vai beigt
        std::cout << std::endl
                  << "Vai turpinat (1) vai beigt (0)? ";
        std::cin >> ok;
    } while (ok == 1);

    return 0;
}

/**************Testa plāns************
m           n       Rezultāts
785938      3       20
123         2       3
123         3       6
9999999     5       45
123         4       Skaitlim 123 nav 4 ciparu
123         0       Ievadits skaitlis nav naturals
0           0       Ievadits skaitlis nav naturals
0           1       Ievadits skaitlis nav naturals
-123        3       Ievadits skaitlis nav naturals
123         -3      Ievadits skaitlis nav naturals
*******************************************/