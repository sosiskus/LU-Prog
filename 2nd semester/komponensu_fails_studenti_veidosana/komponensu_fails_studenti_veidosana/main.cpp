/// Projekts komponensu_fails_studenti_veidosana
/// main.cpp
/**************************************************************
 komponensu_fails_studenti_veidosana.
 Uzrakstīt C++ programmu, kas izveido komponenšu failu ar
 informāciju par studentiem.
 Katrai komponentei jāsatur binārā formā studenta uzvārds,
 vārds, semestra numurs, kurā iegūtas atzīmes, atzīmes 10 priekšmetos.
 Informāciju par studentiem ievada lietotājs no tastatūras kā
 vērtību virkni.
**************************************************************/
/// Autors:  Straujums Uldis
/// Radīts:  v.1.0.; 2008.04.24.
/// Mainīts: v.1.2.; 2013.03.19. Mainīti konstanšu vārdi, klase pārsaukta no
///                              person par Student
/// Mainīts: v.2.0; 2014.03.12.  Pielikta metode fillRecord
/// Mainīts: v.3.0; 28.03.2016.  Atdalīta metožu realizācija no klases deklarācijas; uzlaboti komentāri
/// Mainīts: v.4.0; 22.03.2020   Pievienots testa piemērs
/// Mainīts: 01.04.2021 Programmas kodējums pārveidots par UTF-8

#include <fstream>
#include <iostream>
#include <cstring>
#include "Student.h"
using namespace std;

int main()
{
    ofstream fout1; /// Veidojamā komponenšu faila mainīgais
    ifstream fin1;  /// Izveidotā faila pārbaudei
    Prese s;

    fout1.open("stud.bin", ios::binary);
    /// Secīgas lasīšanas shēmas realizācija failam cin
    s.fillObject(); /// Iegūst pirmo studenta vērtību no tastatūras
    while (!cin.eof())
    {
        s.write(fout1); /// Apstrādā kārtējo dabūto vērtību(ziņas par studentu)
        s.fillObject();
    };

    fout1.close();

    /// Pārbauda izveidotā faila atbilstību ievadītajām vērtībām
    fin1.open("stud.bin", ios::binary);
    while (s.read(fin1))
        s.print(); /// Atkal secīgas lasīšanas shēmas realizācija saīsinātā pierakstā
    fin1.close();
    return 0;
};

/**********************Testu plāns***********************************************
   ievade                                     paredzamais rezultāts
Straujums Uldis 1 5 6 7 8 9 4 5 6 7 8      Straujums Uldis 1 5 6 7 8 9 4 5 6 7 8
Bacis Juris     2 8 7 6 5 4 5 6 7 8 9      Bacis Juris     2 8 7 6 5 4 5 6 7 8 9
Zutis  Andris   1 8 7 6 5 4 5 6 7 8 9      Zutis  Andris   1 8 7 6 5 4 5 6 7 8 9
^Z
===============================================================================
Straujums Uldis 1 5 6 7 8 9 4 5 6 7        Straujums Uldis 1 5 6 7 8 9 4 5 6 7
^Z
===============================================================================
^Z                                         nav nevienas komponentes
*******************************************************************************/
