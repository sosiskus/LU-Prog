/*******************************************
Niktia Klepikovs, nk24033
H2. Dots teksta fails. Saskaitīt tekstā vārdus pēc to garumiem (1-burtīgie, 2-burtīgie utt.).
Programmai statistika pa vārdu garumiem jāsaliek tabulā, kas realizēta kā vārdnīca (STL map).
Programmas rezultātā iegūt failu, kas sastāv no skaitļu pārīšiem,
kurā katram vārdu garumam dots vārdu skaits (piemēram, 1 110, 2 406, 3 632 utt.).
Par vārdiem tiek uzskatītas simbolu virknes, kas atdalītas ar tukšumiem un pieturzīmēm.
Programma izveidota: 04.05.2025.
*******************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>

/**
 * size_t utf8Length(const std::string& str)
 * Funkcija utf8Length(str)
 * Saskaita UTF-8 kodētus simbolus std::string virknē str.
 * Pieņem, ka ievades virkne ir derīgā UTF-8 formātā
 * Atgriež simbolu (nevis baitu) skaitu
 */
size_t utf8Length(const std::string &str)
{
    size_t count = 0;
    for (size_t i = 0; i < str.length(); )
    {
        auto byte = str[i];
        // Noklusetais garums ASII simboliem
        size_t charLen = 1;

        if ((byte & 0x80) == 0) // 0xxxxxxx (ASCII)
        {
            charLen = 1;
        }
        else if ((byte & 0xE0) == 0xC0)// 110xxxxx (2-byte)
        { 
            charLen = 2;
        }
        else if ((byte & 0xF0) == 0xE0)// 1110xxxx (3-byte)
        { 
            charLen = 3;
        }
        else if ((byte & 0xF8) == 0xF0) // 11110xxx (4-byte)
        {
            charLen = 4;
        }

        // Palielinām skaitītāju        
        count++;
        i += charLen;
    }
    return count;
}

int main()
{
    std::string inputFileName;
    std::string outputFileName;

    std::cout << "Ievadiet ievades teksta faila nosaukumu: ";
    std::cin >> inputFileName;
    std::cout << "Ievadiet izvades faila nosaukumu: ";
    std::cin >> outputFileName;

    // Ievades faila atvēršana
    std::ifstream inputFile(inputFileName);
    if (!inputFile.is_open())
    {
        std::cerr << "Nevar atvert ievades failu '" << inputFileName << "'" << std::endl;
        return 1;
    }

    // Vārdnīca vārdu garumu skaita glabāšanai: <garums, skaits>
    std::map<int, int> wordLengthCounts;
    std::string currentWord;
    char ch;

    // Atdalītāju virkne, kas satur visus simbolus, kas tiek uzskatīti par atdalītājiem
    const std::string delimiters = " \t\n\r.,;:!?-\"'()";

    // Nolasa failu pa vienam simbolam līdz faila beigām
    while (inputFile.get(ch))
    {
        // Pārbauda, vai nolasītais simbols 'ch' ir atrodams 'delimiters' virknē
        if (delimiters.find(ch) != std::string::npos)
        {

            // Parbaudam vai tekošais vārds ir tukšs
            if (!currentWord.empty())
            {

                int length = utf8Length(currentWord);

                // Pievieno tā garumu vārdnīcai
                wordLengthCounts[length]++;

                // Pirnt
                // std::cout << "Vards: " << currentWord << ", garums: " << length << std::endl;

                currentWord.clear();
            }
        }
        else
        {
            currentWord += ch;
        }
    }

    // Pārbauda pēdējo vārdu, ja fails beidzas ar vārdu
    if (!currentWord.empty())
    {
        int length = utf8Length(currentWord);
        wordLengthCounts[length]++;
        std::cout << "Vards: " << currentWord << ", garums: " << length << std::endl;
    }

    inputFile.close();

    // Izvades faila atvēršana
    std::ofstream outputFile(outputFileName);
    if (!outputFile.is_open())
    {
        std::cerr << "Nevar atvert izvades failu '" << outputFileName << "'" << std::endl;
        return 1;
    }
    std::cout << "Vardu garumu skaits:" << std::endl;

    // Izvades failā ieraksta vārdnīcas saturu
    for (const auto &pair : wordLengthCounts)
    {
        // Ieraksta vārda garumu un tā skaitu
        outputFile << pair.first << " " << pair.second << std::endl;
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    outputFile.close();

    return 0;
}

/* ------------ Testa Plāns ------------
1. Parasti vārdi ar UTF-8 kodejumu (input1.txt)
Izavades fails: output1.txt
1 1
2 4
3 5
4 1
5 3
6 5
7 1
8 2
10 1

2. Tukšs fails (input2.txt)
Izvades fails: output2.txt
Izvades fails ir tukšs, jo nav vārdu.

3. Fails sastav tikai no atdalītājiem (input3.txt)
Izvades fails: output3.txt
Izvades fails ir tukšs, jo nav vārdu.

4. Secigi atdalītaji priekš vai aiz vārdiem (input4.txt)
Izvades fails: output4.txt
6 5

5. Vārdi ar skaitļiem un citiem simboliem (input5.txt)
Izvades fails: output5.txt
2 1
3 1
6 1
10 2
14 2
27 1
------------------------------------ */