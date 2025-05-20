#include "unitTests.h"
#include "linkedList.h"

/**
 * bool compareLists(elem* first, elem* firstExpected)
 * compareLists(first, firstExpected)
 * Salīdzina divus vienvirziena saišu sarakstus first un firstExpected, atrgriežot true, ja tie ir vienādi.
 * Atgriež true, ja abi saraksti ir vienādi pēc kārtas un vērtībām, false pretējā gadījumā.
 */
bool compareLists(elem* first, elem* firstExpected)
{
    elem* current = first;
    elem* currentExpected = firstExpected;
    bool result = true;
    while (current != nullptr && currentExpected != nullptr)
    {
        if (current->num != currentExpected->num)
        {
            result = false;
            break;
        }
        current = current->next;
        currentExpected = currentExpected->next;
    }
    return result;
}


bool testInsertAfterExistingElement()
{
    elem* first = nullptr;
    elem* last = nullptr;

    // saraksts {1, 2, 3}
    append(first, last, 1);
    append(first, last, 2);
    append(first, last, 3);

    insert(first, last, 4, 2);
    // saraksts {1, 2, 4, 3}

    elem* firstExpected = nullptr;
    elem* lastExpected = nullptr;
    append(firstExpected, lastExpected, 1);
    append(firstExpected, lastExpected, 2);
    append(firstExpected, lastExpected, 4);
    append(firstExpected, lastExpected, 3);
    // saraksts {1, 2, 4, 3}

    // salīdzinām sarakstus
    bool result = compareLists(first, firstExpected);

    del(first, last);
    del(firstExpected, lastExpected);
    return result;
}

bool testInsertAtEnd()
{
    elem* first = nullptr;
    elem* last = nullptr;

    // saraksts {1, 2, 3}
    append(first, last, 1);
    append(first, last, 2);
    append(first, last, 3);

    insert(first, last, 4, 3);
    // saraksts {1, 2, 3, 4}

    elem* firstExpected = nullptr;
    elem* lastExpected = nullptr;
    append(firstExpected, lastExpected, 1);
    append(firstExpected, lastExpected, 2);
    append(firstExpected, lastExpected, 3);
    append(firstExpected, lastExpected, 4);
    // saraksts {1, 2, 3, 4}

    // salīdzinām sarakstus
    bool result = compareLists(first, firstExpected);

    del(first, last);
    del(firstExpected, lastExpected);
    return result;
}



bool testInsertAfterNonExistingElement()
{
    elem* first = nullptr;
    elem* last = nullptr;

    // saraksts {1, 2, 3}
    append(first, last, 1);
    append(first, last, 2);
    append(first, last, 3);

    insert(first, last, 4, 5); // 5 nav sarakstā, insert neko nedara
    // saraksts {1, 2, 3}

    elem* firstExpected = nullptr;
    elem* lastExpected = nullptr;
    append(firstExpected, lastExpected, 1);
    append(firstExpected, lastExpected, 2);
    append(firstExpected, lastExpected, 3);
    // saraksts {1, 2, 3}

    // salīdzinām sarakstus
    bool result = compareLists(first, firstExpected);

    del(first, last);
    del(firstExpected, lastExpected);
    return result;
}




bool testInsertAfterFirstElement()
{
    elem* first = nullptr;
    elem* last = nullptr;

    // saraksts {1, 2, 3}
    append(first, last, 1);
    append(first, last, 2);
    append(first, last, 3);

    insert(first, last, 4, 1);
    // saraksts {1, 4, 2, 3}

    elem* firstExpected = nullptr;
    elem* lastExpected = nullptr;
    append(firstExpected, lastExpected, 1);
    append(firstExpected, lastExpected, 4);
    append(firstExpected, lastExpected, 2);
    append(firstExpected, lastExpected, 3);
    // saraksts {1, 4, 2, 3}

    // salīdzinām sarakstus
    bool result = compareLists(first, firstExpected);

    del(first, last);
    del(firstExpected, lastExpected);
    return result;
}




bool testInsertMultipleEqualElement()
{
    elem* first = nullptr;
    elem* last = nullptr;

    // saraksts {1, 2, 3, 2}
    append(first, last, 1);
    append(first, last, 2);
    append(first, last, 3);
    append(first, last, 2);

    insert(first, last, 4, 2); // ievietos tikai pēc pirmā sastaptā skaitļa
    // saraksts {1, 4, 2, 3, 2}

    elem* firstExpected = nullptr;
    elem* lastExpected = nullptr;
    append(firstExpected, lastExpected, 1);
    append(firstExpected, lastExpected, 2);
    append(firstExpected, lastExpected, 4);
    append(firstExpected, lastExpected, 3);
    append(firstExpected, lastExpected, 2);
    // saraksts {1, 4, 2, 3}

    // salīdzinām sarakstus
    bool result = compareLists(first, firstExpected);

    del(first, last);
    del(firstExpected, lastExpected);
    return result;
}



bool testInsertAfterOneElement()
{
    elem* first = nullptr;
    elem* last = nullptr;

    // saraksts {1}
    append(first, last, 1);

    insert(first, last, 2, 1);
    // saraksts {1, 2}

    elem* firstExpected = nullptr;
    elem* lastExpected = nullptr;
    append(firstExpected, lastExpected, 1);
    append(firstExpected, lastExpected, 2);
    // saraksts {1, 2}

    // salīdzinām sarakstus
    bool result = compareLists(first, firstExpected);

    del(first, last);
    del(firstExpected, lastExpected);
    return result;
}

