#include <iostream>

int main()
{
    int n;
    std::cout << "Enter number of rows: ";
    std::cin >> n;

    int start1 = 0, start2 = 1, start3 = 2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j % 3 == start1)
            {
                std::cout << "*";
            }
            else if (j % 3 == start2 || j % 3 == start3)
            {
                std::cout << "_";
            }
        }
        std::cout << std::endl;

        if (start1 == 0)
        {
            start1 = 1;
            start2 = 2;
            start3 = 0;
        }
        else if (start2 == 0)
        {
            start1 = 0;
            start2 = 1;
            start3 = 2;
        }
        else
        {
            start1 = 2;
            start2 = 0;
            start3 = 1;
        }
    }
}