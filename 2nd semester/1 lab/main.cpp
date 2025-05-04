#include <iostream>
#include <fstream>
#include <algorithm>

int main()
{
    std::fstream file;
    char sim;
    std::string line;
    int simCount = 0;

    file.open("text.txt", std::ios::in);
    if (!file)
    {
        std::cout << "File not found!" << std::endl;
        return 1;
    }

    std::cout << "Enter a symbol: ";
    std::cin.get(sim);

    while (std::getline(file, line))
    {
       std::for_each(line.begin(), line.end(), [&](char c) {
            if (c == sim)                                       
            {
                simCount++;
            }
        });
    }

    std::cout << "Symbol " << sim << " was found " << simCount << " times." << std::endl;
}