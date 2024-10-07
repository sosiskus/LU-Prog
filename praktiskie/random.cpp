#include <iostream>
#include <iomanip>

int main() 
{
  int table[10][10];

  for (int i = 1; i <= 10; i++)
  {
    for (int j = 1; j <= 10; j++)
    {
      table[i-1][j-1] = i * j;
    }
  }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
        std::cout << std::setw(3) <<table[i][j] << " ";
        }
        std::cout << std::endl;
    }
}