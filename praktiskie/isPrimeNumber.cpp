#include <iostream>

int main() {
    int n;
    std::cin >> n;
    if (n <= 2)
    {
        std::cout << "true" << std::endl;
        return 0;
    }

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            std::cout << "false" << std::endl;
            return 0;
        }
    }

    std::cout << "true" << std::endl;
}