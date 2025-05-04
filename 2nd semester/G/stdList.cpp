/*******************************************
Niktia Klepikovs, nk24033
G20. Uzrakstīt funkciju, kas ieliek sarakstā elementu ar vērtību n pēc pirmā elementa ar vērtību m.
Programma izveidota: 25.03.2025.
*******************************************/
#include <list>
#include <iterator>
#include <iostream>

/**
 * Funkcija print —
 * Izdrukā visus saraksta elementus vienā rindā, atdalītus ar atstarpi
 */
void print(const std::list<int>& lst)
{
    for (int num : lst)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

/**
 * void insert(std::list<int>& lst, int m, int n)
 * Funkcija insert(lst, m, n) —
 * Ievieto jaunu elementu stl sarakstā `lst` int ar vērtību `n` pēc pirmā atrastā elementa ar vērtību `m`
 * Neko neatgriež, modificē sarakstu pa tiešo
 */
void insert(std::list<int>& lst, int m, int n)
{
    for (auto it = lst.begin(); it != lst.end(); ++it)
    {
        if (*it == m)
        {
            // Ievieto aiz atrastā elementa
            ++it;
            lst.insert(it, n);
            return;
        }
    }

    // Ja nav atrasts:
    std::cout << "Number after which to insert not found" << std::endl;
}

int main()
{
    std::list<int> lst;

    // Pieprasam lietotājam ievadīt saraksta garumu
    int n = 0;
    std::cout << "Input list length: ";
    std::cin >> n;
    std::cout << std::endl;

    if (n <= 0)
    {
        std::cout << "List length must be greater than 0" << std::endl;
        return 0;
    }

    // Pieprasam lietotājam ievadīt saraksta elementus
    int num = 0;
    for (int i = 0; i < n; ++i)
    {
        std::cout << "input: ";
        std::cin >> num;
        lst.push_back(num);
    }

    print(lst); // Izvada sākotnējo sarakstu

    // Pieprasam lietotājam ievadīt m un n
    int numToFind = 0, numToInsert = 0;
    std::cout << "Input number after which to insert: ";
    std::cin >> numToFind;
    std::cout << "Input number which must be inserted: ";
    std::cin >> numToInsert;
    std::cout << std::endl;

    // Ievietošana
    insert(lst, numToFind, numToInsert);

    print(lst);
}


/******** TESTA PLANS   ******** 
1	Tukšs saraksts	                    n = 0	                                Izvade: List length must be greater than 0
3	Ievietošana pēc esoša elementa	    n = 3, ievade: 1 2 3, m = 2, n = 4,     Izvade: 1 2 4 3
4	Ievietošana pēdējā pozīcijā	        n = 2, ievade: 10 20, m = 20, n = 30	Izvade: 10 20 30
5	Ievietot pēc neesoša elementa	    n = 3, ievade: 5 6 7, m = 9, n = 99	    Izvade: Number after which to insert not found
6   Ievieto pec pirmā elementa          n = 3, ievade: 1 2 3, m = 1, n = 4      Izvade: 1 4 2 3
7   Vairakie elementi vienādi           n = 4, ievade: 1 2 2 4, m = 2, n = 5    Izvade: 1 2 5 2 4
*/