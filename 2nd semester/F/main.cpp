/*******************************************
Niktia Klepikovs, nk24033
F20. Dots teksta fails, kurā atrodas sintaktiski pareizs C++ programmas teksts.
Sastādīt programmu, kura failā izvada šo programmas tekstu bez komentāriem.
Drīkst pieņemt, ka teksta literāļos neparādīsies komentāru sākuma vai beigu apzīmējuma simboli.
Programma izveidota: 13.02.2025.
*******************************************/
#include <algorithm>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>

/**
 * void removeInlineComments(std::string& line)
 * Funkcija removeInlineComments(line) -
 * Mekle rindina line komentara sakuma simbolu (//) un izgriez komentarus no rindas.
 * Neko neatgriez, jo funkcija maina rindinas saturu.
 */
void removeInlineComments(std::string &line)
{
    for (int i = 0; i < line.size(); i++)
    {
        if (line[i] == '/' && line[i + 1] == '/')
        {
            line = line.substr(0, i);
            break;
        }
    }
}

/**
 * int findMultilineComments(std::string& line, const int isInsideComment)
 * Funkcija findMultilineComments(line, isInsideComment) -
 * Mekle rindina line komentara sakuma simbolu (/*) un komentara beigu simbolu (* /) un izgriez komentara dalu no rindinas.
 * Ka argumentu pieneem line - rindinu, kur meklet komentarus, un isInsideComment - vai padota rindiņa ir jau iekšā vairakrindinas komentara.
 * 
 * Atgriez 0, ja nav atrasts komentara sakuma vai beigu simbols.
 * Atgriez 1, ja atrasts komentara sakuma simbols.
 * Atgriez 2, ja atrasts komentara beigu simbols.
 */
int findMultilineComments(std::string &line, const int isInsideComment)
{
    int inComment = 0;
    for (int i = 0; i < line.size(); i++)
    {
        if (line[i] == '/' && line[i + 1] == '*') // Komentara sakums
        {
            if (isInsideComment == 1)
                continue;

            inComment = 1;

            // check if line contains both start and end comment
            for (int j = i + 2; j < line.size(); j++)
            {
                if (line[j] == '*' && line[j + 1] == '/')
                {
                    inComment = 0;
                    // remove only comment
                    line = line.substr(0, i) + line.substr(j + 2);
                    break;
                }
            }

            // remove comment start
            if (inComment != 0)
                line = line.substr(0, i);

            break;
        }
        else if (line[i] == '*' && line[i + 1] == '/') // Komentara beigas
        {
            inComment = 2;
            // remove comment end
            line = line.substr(i + 2);
            break;
        }
    }
    return inComment;
}

/**
 * void writeToFile(std::fstream& output, std::string& line)
 * Funkcija writeToFile(output, line) -
 * Raksta rindinu line failā output
 * Neko neatgriez
 */
void writeToFile(std::fstream &output, std::string &line)
{
    output << line << std::endl;
}

int main()
{
    std::fstream input;
    std::fstream output;
    std::string line;

    const std::string outputFileName = "output.txt";
    std::string inputFileName;
    int ok = 1;

    do
    {
        std::cout << "Enter input file name: ";
        std::cin >> inputFileName;

        input.open(inputFileName, std::ios::in);
        if (!input.is_open())
        {
            std::cout << "Input file not found!" << std::endl;
            return 1;
        }

        output.open(outputFileName, std::ios::out);
        if (!output.is_open())
        {
            std::cout << "Output file not found!" << std::endl;
            return 1;
        }

        int multilineComment = 0;
        while (std::getline(input, line))
        {
            removeInlineComments(line);           // Remove inline comments
            auto m = findMultilineComments(line, multilineComment); // Find multiline comments
            if (m == 1)                           // Multiline comment started
            {
                multilineComment = 1;
                writeToFile(output, line); // Write line without comment start
                continue;
            }
            else if (m == 2) // Multiline comment ended
            {
                multilineComment = 0;
                writeToFile(output, line); // Write line without comment end
                continue;
            }

            if (multilineComment != 1) // If not inside multiline comment, write line
                writeToFile(output, line);
        }

        input.close();
        output.close();

        std::cout << "Output file created!" << std::endl;

        std::cout << "Continue? (1 - yes, 0 - no): ";
        std::cin >> ok;

    } while (ok == 1);
}

/**** TESTA PLANS ****
 * "input1.txt" - fails ar vienu rindinu, kas satur komentaru
 * "input2.txt" - fails ar vairakam rindinam, kas satur komentarus
 * "input3.txt" - fails kur vairakrindu komentari sakas uz vienas rindas ar komentara beigu simbolu
 * "input4.txt" - fails kur nav komentaru
 * "input5.txt" - fails kur ir tukšie komentari
 */