#include <iostream>

struct elem
{
    int num;
    elem *next;
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

elem *find(elem *first, elem *last, int sk)
{

    elem *current = first;
    while (current != nullptr)
    {
        if (current->num == sk)
            return current;
        current = current->next;
    }
    return nullptr;
}

void append(elem *&first, elem *&last, int sk)
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

elem* erase(elem* &first, elem* &last, elem* &p)
{
    elem* current = first;
    elem* prev = nullptr;
    while (current != nullptr)
    {
        if (current == p)
        {
            if (prev == nullptr)
            {
                first = current->next;
                delete current;
                return first;
            }
            else
            {
                prev->next = current->next;
                delete current;
                return prev->next;
            }
        }
        prev = current;
        current = current->next;
    }
    return nullptr;
}

void eraseAllInts(elem* &first, elem* &last, int numToErase)
{
    elem* current = first;
    while (current != nullptr)
    {
        std::cout << current->num << std::endl;
        if (current->num == numToErase)
        {
            current = erase(first, last, current);
        }
        else
        {
            current = current->next;
        }
    }
}

void del(elem *&first, elem *&last)
{
    elem *current = first;
    while (first != nullptr)
    {
        current = first;
        first = first->next;
        delete current;
    }
    last = nullptr;
}

void print(elem *first, elem *last)
{
    elem *current = first;
    while (current != nullptr)
    {
        std::cout << current->num << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void eraseEven(elem* &first, elem* &last)
{
    elem* current = first;
    while (current != nullptr)
    {
        std::cout << current->num << std::endl;
        if (current->num % 2 == 1)
        {
            current = erase(first, last, current);
        }
        else
        {
            current = current->next;
        }
    }
}

int deleteOds(elem* &first, elem* &last)
{
    elem* current = first;
    elem* prev = nullptr;
    bool del = false;
    int delCount = 0;
    while(current)
    {
        if(current->num % 2 == 1) // nepara
        {
            // check if previous is nepara
            if (prev != nullptr)
            {
                if(prev->num % 2 == 1)
                {
                    std::cout << "delete: " << prev->num << std::endl;
                    // delete prev
                    prev = erase(first, last, prev);
                    std::cout << "dfd" << std::endl;
                    current = prev->next;
                    del = true;
                    delCount++;
                }
            }
        }
        if(!del)
        {
            prev = current;
            current = current->next;
        }
        del = false;
    }

    return delCount;
}

void deleteOdsCompletely(elem* &first, elem* &last){
    while(deleteOds(first, last) != 0){}
}

elem* insertBefore(elem* &first, elem* &last, elem* &p, int num)
{
    elem* current = first;
    elem* prev = nullptr;
    while(current)
    {
        if(current == p)
        {
            std::cout << "inserting before: " << current->num << std::endl;
            auto newElem = new elem(num);
            if(prev == nullptr)
            {
                newElem->next = first;
                first = newElem;
                return newElem;
            }
            else
            {
                newElem->next = current;
                prev->next = newElem;
                return newElem;
            }
        }
        prev = current;
        current = current->next;
    }
    return nullptr;
}

// make function to insert -1 before any even number
void insertBeforeEven(elem* &first, elem* &last)
{
    elem* p = first;
    while(p)
    {
        if (p->num == 0)
        {
            p = insertBefore(first, last, p, -1);
            if (p)
            {
                p = p->next;
            }
        }
        p = p->next;
    }
}

int main()
{
    elem *first = nullptr;
    elem *last = nullptr;

    int n = 0;
    std::cout << "Input list length: ";
    std::cin >> n;
    std::cout << std::endl;

    int num = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> num;
        append(first, last, num);
    }
    print(first, last);

    // eraseEven(first, last);
    // eraseAllInts(first, last, 5);
    // deleteOds(first, last);
    insertBeforeEven(first, last);
    std::cout << "After erasing" << std::endl;

    print(first, last);
    
    del(first, last);
}
