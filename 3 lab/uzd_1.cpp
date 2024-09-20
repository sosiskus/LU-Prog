#include <iostream>

int main()
{
    int n;
    std::cout << "Enter number of numbers: ";
    std::cin >> n;

    int max = 0;
    do
    {
        int m;
        std::cout << "Enter number: ";
        std::cin >> m;

        if (m > max)
            max = m;
       
    } while (--n);

    std::cout << "Max number is: " << max << std::endl;
    
}