#include <iostream>

int main()
{
    int n;
    std::cout << "Enter number of rows: ";
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            std::cout << '*';
        }
        std::cout << std::endl;
    }
    
}