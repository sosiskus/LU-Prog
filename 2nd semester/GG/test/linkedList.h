#pragma once

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
elem* find (elem* first, elem* last, int sk);

/**
 * void insert(elem* &first, elem* &last, int n, int m)
 * Funkcija insert(first, last, n, m) —
 * Pievieno jaunu elementu vienvirzienu saistitā sarakstā `first` ar vērtību `n` aiz elementa ar vertibu `m`
 * Neko neatgriež, modificē sarakstu pa tiešo
 */
void insert(elem* &first, elem* &last, int n, int m);

/**
 * void append(elem* &first, elem* &last, int sk)
 * Funkcija append(first, last, sk) —
 * Pievieno jaunu elementu saraksta ar vērtību `sk` saistītā saraksta beigās
 * Ja saraksts ir tukšs, pievienotais elements kļūst par pirmo un pēdējo elementu
 * Nekā neatgriež
 */
void append(elem* &first, elem* &last, int sk);

/**
 * void del(elem* &first, elem* &last)
 * Funkcija del(first, last) —
 * Atbrīvo atmiņu visiem saraksta elementiem un iztīra sarakstu
 * Nekā neatgriež
 */
void del(elem* &first, elem* &last);