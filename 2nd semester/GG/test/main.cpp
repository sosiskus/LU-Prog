/*******************************************
Niktia Klepikovs, nk24033
GS20. Uzrakstīt funkciju, kas ieliek sarakstā elementu ar vērtību n pēc pirmā elementa ar vērtību m.
Programma izveidota: 20.05.2025.
*******************************************/
#include <iostream>
#include "unitTests.h"

int main()
{
    // Testējam funkcijas

    // Pārbaudām, ievietojot elementu pēc skaitla
    if (testInsertAfterExistingElement())
        std::cout << "\033[32mTest 1 passed\033[0m" << std::endl;
    else
        std::cout << "\033[31mTest 1 failed\033[0m" << std::endl;

    // Pārbaudām, ievietojot elementu saraksta beigās
    if (testInsertAtEnd())
        std::cout << "\033[32mTest 2 passed\033[0m" << std::endl;
    else
        std::cout << "\033[31mTest 2 failed\033[0m" << std::endl;

    // Pārbaudām, ievietojot elementu pēc neesoša skaitļa
    if (testInsertAfterNonExistingElement())
        std::cout << "\033[32mTest 3 passed\033[0m" << std::endl;
    else
        std::cout << "\033[31mTest 3 failed\033[0m" << std::endl;

    // Pārbaudām, ievietojot elementu pēc pirmā elementa
    if (testInsertAfterFirstElement())
        std::cout << "\033[32mTest 4 passed\033[0m" << std::endl;
    else
        std::cout << "\033[31mTest 4 failed\033[0m" << std::endl;

    // Pārbaudām, ievietojot elementu pēc pirmā sastaptā skaitļa
    if (testInsertMultipleEqualElement())
        std::cout << "\033[32mTest 5 passed\033[0m" << std::endl;
    else
        std::cout << "\033[31mTest 5 failed\033[0m" << std::endl;

    // Pārbaudām, ievietojot elementu sarakstā ar vienu elementu
    if (testInsertAfterOneElement())
        std::cout << "\033[32mTest 6 passed\033[0m" << std::endl;
    else
        std::cout << "\033[31mTest 6 failed\033[0m" << std::endl;

}