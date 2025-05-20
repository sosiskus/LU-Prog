/*******************************************
Niktia Klepikovs, nk24033
GG20. Uzrakstīt funkciju, kas ieliek sarakstā elementu ar vērtību n pēc pirmā elementa ar vērtību m.
Programma izveidota: 20.05.2025.
*******************************************/
#include <iostream>

struct elem
{
    int num;
    elem* next;
    elem(int n)
    {
        num = n;
        next = nullptr;
    }
};

/**
 * elem* find(elem* first, elem* last, int sk)
 * Funkcija find(first, last, sk) —
 * Meklē elementu saraksta ar vērtību `sk` sarakstā.
 * Atgriež pointeri uz atrasto elementu vai `nullptr`, ja nav atrasts.
 */
elem* find (elem* first, elem* last, int sk)
{

    elem* current = first;
    while(current != nullptr)
    {
        if (current->num == sk) // Ja atrasta meklētā vērtība
            return current;
        current = current->next;
    }
    throw "Element not found"; // Ja nav atrasts, izmetam izņēmumu
}

/**
 * void insert(elem* &first, elem* &last, int n, int m)
 * Funkcija insert(first, last, n, m) —
 * Pievieno jaunu elementu vienvirzienu saistitā sarakstā `first` ar vērtību `n` aiz elementa ar vertibu `m`
 * Neko neatgriež, modificē sarakstu pa tiešo
 */
void insert(elem* &first, elem* &last, int n, int m)
{
    elem* p;
    try
    {
        p = find(first, last, m);
    }
    catch (const char* msg)
    {
        std::cout << msg << std::endl;
        return;
    }
    catch (...)
    {
        std::cout << "Unknown error" << std::endl;
        return;
    }


    elem* current = first;
    while(current)
    {
        if(current == p)  // Ja atrasts elements, pēc kura jāievieto
        {
            auto newElem = new elem(n);

            if(current->next == nullptr) // Ja ievieto pēdējā pozīcijā
            {
                newElem->next = nullptr;    // Jaunais elements kļūst par pēdējo
                current->next = newElem;    // Iepriekšējais elements norāda uz jauno
                last = newElem;             // Atjaunojam pēdējo rādītāju
                return;
            }
            else
            {
                newElem->next = current->next; // Jaunais elements norāda uz nākamo elementu
                current->next = newElem;       // Iepriekšējais elements norāda uz jauno
                return;
            }
        }
        current = current->next; // Pārejam uz nākamo elementu
    }
}

/**
 * void append(elem* &first, elem* &last, int sk)
 * Funkcija append(first, last, sk) —
 * Pievieno jaunu elementu saraksta ar vērtību `sk` saistītā saraksta beigās
 * Ja saraksts ir tukšs, pievienotais elements kļūst par pirmo un pēdējo elementu
 * Nekā neatgriež
 */
void append(elem* &first, elem* &last, int sk)
{
    auto p = new elem(sk);
    if (first == nullptr)
    {
        // Ja saraksts ir tukšs, šis kļūst par pirmo un pēdējo
        last = first = p;
    }
    else
    {
        // Pretējā gadījumā pievieno beigās
        last->next = p;
        last = p;
    }

}

/**
 * void del(elem* &first, elem* &last)
 * Funkcija del(first, last) —
 * Atbrīvo atmiņu visiem saraksta elementiem un iztīra sarakstu
 * Nekā neatgriež
 */
void del(elem* &first, elem* &last)
{
    elem* current = first;
    while(first != nullptr)
    {
        current = first; // Saglabā pointeri uz pašreizējo elementu
        first = first->next; // Pārejam uz nākamo
        delete current; // Atbrīvo iepriekšējo
    }
    last = nullptr;     // Atzimejam arī pēdējo kā tukšu
}

/**
 * void print(elem* first, elem* last)
 * Funkcija print(first, last) —
 * Izdrukā visus saistītā saraksta elementus rindā, atdalītus ar atstarpi
 * Nekā neatgriež
 */
void print(elem* first, elem* last)
{
    elem* current = first;
    while(current != nullptr)
    {
        std::cout << current->num << " ";
        current = current->next;
    }
    std::cout << std::endl;
}


int main()
{
    elem* first = nullptr;
    elem* last = nullptr;

    // pieprasam lietotājam ievadīt saraksta garumu
    int n = 0;
    std::cout << "Input list length: ";
    std::cin >> n;
    std::cout << std::endl;
    if (n <= 0)
    {
        std::cout << "List length must be greater than 0" << std::endl;
        return 0;
    }

    // pieprasam lietotājam ievadīt saraksata elementus
    int num = 0;
    for (int i = 0; i < n; i++)
    {

        std::cout << "input: " << std::endl;
        std::cin >> num;
        append(first, last, num);
    }
    print(first, last); // izvada ievadito sarakstu

    // pieprasam lietotājam ievadīt skaitlus m un n
    int numToFind = 0, numToInsert = 0;
    std::cout << "Input number after which to insert: ";
    std::cin >> numToFind;
    std::cout << "Input number which must be inserted: ";
    std::cin >> numToInsert;
    std::cout << std::endl;

    // pievienojam skaitli n pēc skaitļa m
    insert(first, last, numToInsert, numToFind);
    print(first, last);


    del(first, last);
}


/******** TESTA PLANS   ******** 
1	Tukšs saraksts	                    n = 0	                                Izvade: List length must be greater than 0
3	Ievietošana pēc esoša elementa	    n = 3, ievade: 1 2 3, m = 2, n = 4,     Izvade: 1 2 4 3
4	Ievietošana pēdējā pozīcijā	        n = 2, ievade: 10 20, m = 20, n = 30	Izvade: 10 20 30
5	Ievietot pēc neesoša elementa	    n = 3, ievade: 5 6 7, m = 9, n = 99	    Izvade: Number after which to insert not found
6   Ievieto pec pirmā elementa          n = 3, ievade: 1 2 3, m = 1, n = 4      Izvade: 1 4 2 3
7   Vairakie elementi vienādi           n = 4, ievade: 1 2 2 4, m = 2, n = 5    Izvade: 1 2 5 2 4
*/