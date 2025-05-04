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
Funkcija find(first, last, sk)
atgriez noradi uz atrasto elementu
*/

elem* find (elem* first, elem* last, int sk)
{

    elem* current = first;
    while(current != nullptr)
    {
        if (current->num == sk)
            return current;
        current = current->next;
    }
    return nullptr;
}

void append(elem* &first, elem* &last, int sk)
{
    auto p = new elem(sk);
    if (first == nullptr)
    {
        // add first
        last = first = p;

    }
    else
    {
        // push back
        last->next = p;
        last = p;
    }

}

void del(elem* &first, elem* &last)
{
    elem* current = first;
    while(first != nullptr)
    {
        current = first;
        first = first->next;
        delete current;
    }
    last = nullptr;
}

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

    int n = 0;
    std::cout << "Input list length: ";
    std::cin >> n;
    std::cout << std::endl;

    int num = 0;
    for (int i = 0; i < n; i++)
    {

        std::cout << "input: " << std::endl;
        std::cin >> num;
        append(first, last, num);
    }
    print(first, last);

    int numToFind = 0;
    std::cout << "Input num to find: ";
    std::cin >> numToFind;
    std::cout << std::endl;


    std::cout << ((find(first, last, numToFind) == nullptr) ? "Number not found" : "Number found" )<< std::endl;
    del(first, last);
    print(first, last);
}
