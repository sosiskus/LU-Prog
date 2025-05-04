#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <cstdint>

int main()
{
    std::fstream file;
    std::string line;
    uint8_t simMap[256] = { 0 };

    file.open("text.txt", std::ios::in);
    if (!file)
    {
        std::cout << "File not found!" << std::endl;
        return 1;
    }



    while (std::getline(file, line))
    {
       std::for_each(line.begin(), line.end(), [&](char c) {
            simMap[c]++;
        });
    }

    for (int key = 0; key < 256; key++)
    {
        int value = simMap[key];
        if (value == 0)
            continue;
            
        std::cout << "Symbol " << (char)key << " was found " << value << " times." << std::endl;
    }
}