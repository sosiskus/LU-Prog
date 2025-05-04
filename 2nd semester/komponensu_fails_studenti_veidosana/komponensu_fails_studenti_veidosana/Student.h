#pragma once
#include <iostream>
using namespace std;

const int IZD_SIZE = 20;
const int NOS_SIZE = 20;

class Prese
{
private:
   char nos[NOS_SIZE + 1]; /// Beigās '\0' simbols
   char veids;
   int reiz;
   int val;
   char izdevejs[IZD_SIZE + 1]; /// Beigās '\0' simbols
   int izdIndx;

public:
   Prese();

   /** Metode fillObject() -
      aizpilda Student objekta laukus ar vērtībām.
      Vērtības ievada lietotājs no tastatūras. **/
   void fillObject();
   /** Metode write(fout) -
      ieraksta Student objekta laukus failā,
      kas piesaistīts faila objektam fout. **/
   void write(ostream &fout);
   /** Metode read(fin) -
      nolasa Student objekta laukus no faila,
      kas piesaistīts faila objektam fin,
      ieraksta nolasīto informāciju Student objektā. **/
   bool read(istream &fin);
   /** Metode print() -
      izdrukā Student objekta laukus **/
   void print();

   bool select(istream &fin, const char* nos)
   {
      while(read(fin))
      {
         if (strcmp(nos, this->nos) == 0)
            return true;
      }
      return false;
   };
};
