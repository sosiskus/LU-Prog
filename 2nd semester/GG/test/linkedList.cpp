#include "linkedList.h"
#include <iostream>

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

void insert(elem* &first, elem* &last, int n, int m)
{
    elem* p;
    try
    {
        p = find(first, last, m);
    }
    catch (const char* msg)
    {
        return;
    }
    catch (...)
    {
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