#include <iostream>

int main()
{
    int n;
    std::cout << "Enter number of rows: ";
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j % 3 == i % 3)
            {
                std::cout << "*";
            }
            else
            {
                std::cout << "_";
            }
        }
        std::cout << std::endl;
    }
}