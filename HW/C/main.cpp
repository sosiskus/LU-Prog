#include <iostream>
#include <string>
#include <utility>

/**
 * std::pair<int, int> markHorseMoves(bool chessBoard[8][8], int number, int letterToNumber)
 * Funkcija markHorseMoves(chessBoard, number, letterToNumber) -
 * Iezime saha laukumu, kur zirgs var parvietoties, balstoties uz zirga poziciju šahā laukumā, piem. a2, b6
 * Atgriež divus skaitlus - zirga pozicija šaha laukumā, koordinašu formatā piem. a2 -> 0, 6
 */
std::pair<int, int> markHorseMoves(bool chessBoard[8][8], int number, char letter)
{
    int letterToNumber = letter - 'a'; // Konvertējam burtu uz skaitli, 0 - 7
    number = 7 - --number;             // Konvertējam skaitli no 1 - 7 uz skaitli, 7 - 0, lai pareizi iezimetu šaha laukumu

    // Parbaudam visus iespejamos gajienus, kuros zirgs var parvietoties
    for (int i = -2; i <= 2; i++) // 2 rutinas no vina starta pozicijas pa kreisi un 2 rutinas pa labi
    {
        for (int j = -2; j <= 2; j++) // 2 rutinas no vina starta pozicijas uz apaksu un 2 rutinas uz augsu
        {
            // Zirgs iet uz visiem iepsejamam vietam, iznemot taisnas linijas un diagonales
            // Parbaudam ka nav taisna linija un nav diagonale
            if (i == 0 || j == 0 || i == j || i == -j)
                continue; // Ja ir taisna linija vai diagonale, tad turpinam ciklu

            // Parbaudam ka zirgs neiziet arpus sahmatu laukuma
            if (number + i >= 0 && number + i < 8 && letterToNumber + j >= 0 && letterToNumber + j < 8)
                chessBoard[number + i][letterToNumber + j] = true; // Ja zirgs neiziet arpus saha laukumam, tad iezimejam laukumu
        }
    }

    return {letterToNumber, number};
}

/**
 * void printChessBoard(bool chessBoard[8][8], int x, int y)
 * Funkcija printChessBoard(chessBoard, x, y) -
 * Izvada saha laukumu uz ekrana, kur zirgs atrodas pozicija x, y
 * Neko neatgriež
 */
void printChessBoard(bool chessBoard[8][8], int x, int y)
{
    // Izvadam šaha laukumu uz ekrana
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            // Ja zirgs atrodas šaja pozicija, tad izvadam Z, citādi 0 vai X
            if (i == y && j == x)
            {
                std::cout << "Z ";
            }
            else
            {
                // Ja šahā laukumā ir iezimets true, tad izvadam X, citādi 0
                std::cout << (chessBoard[i][j] ? "X " : "0 ");
            }
        }
        std::cout << std::endl;
    }
}

int main()
{
    int ok = 1;
    do
    {
        std::string place;
        std::cout << "Ievadiet vietu, kur atrodas zirdzins (piem. a2) (burti: a - h, cipari: 1 - 8): ";
        std::cin >> place;

        // Parbaudam vai ievadita vietas garums ir 2
        if (place.length() != 2)
        {
            std::cout << "Jaievada tikai 2 rakstzimes" << std::endl;
            continue;
        }

        char letter = std::tolower(place[0]); // Pārveidojam burtu uz mazo, lai varetu ievadit gan lielos gan mazos burtus
        int number = place[1] - '0';          // Pārveidojam rakstzimi uz integer skaitli

        // Parbaudam vai ievaditais burts ir pareizas robezas
        if (letter < 'a' || letter > 'h')
        {
            std::cout << "Burts ir arpus robezam" << std::endl;
            continue;
        }

        // Parbaudam vai ievaditais cipars ir pareizas robezas
        if (number < 1 || number > 8)
        {
            std::cout << "Cipars ir arpus robezam" << std::endl;
            continue;
        }

        // Izveidojam masivu, kas reprezente šaha laukumu
        bool chessBoard[8][8] = {false};

        // Iezimejam šaha laukumu, kur zirgs var parvietoties
        auto [x, y] = markHorseMoves(chessBoard, number, letter);

        std::cout << std::endl << "Saha laukums (ar Z apzimeta zirga pozicija, ar X apzimetas pozicijas, kurus apdraud zirdzins): " << std::endl;

        // Izvadam šaha laukumu uz ekrana
        printChessBoard(chessBoard, x, y);

        std::cout << "Turpinat? (1) vai (0): ";
        std::cin >> ok;
    } while (ok != 0);

    return 0;
}