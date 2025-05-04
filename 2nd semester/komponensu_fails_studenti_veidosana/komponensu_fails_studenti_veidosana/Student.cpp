#include <cstring>
#include "Student.h"

Prese::Prese()
{
};
/** Metode fillObject() -
   aizpilda Prese objekta laukus ar vērtībām.
   Vērtības ievada lietotājs no tastatūras. **/
void Prese::fillObject()
{
   // get all the values from the user use getline for string
   cout << "Ievadiet preses veidu: ";
   cin >> veids;
   cout << "Ievadiet preses nosaukumu: ";
   cin.ignore(1); // ignore the newline character left in the buffer
   cin.getline(nos, NOS_SIZE);
   cout << "Ievadiet preses reizes skaitu: ";
   cin >> reiz;
   cout << "Ievadiet preses valsti: ";
   cin >> val;
   cout << "Ievadiet izdevēja nosaukumu: ";
   cin.ignore(1); // ignore the newline character left in the buffer
   cin.getline(izdevejs, IZD_SIZE);
   cout << "Ievadiet izdevēja indeksu: ";
   cin >> izdIndx;
   cout << endl;
}
/** Metode write(fout) -
   ieraksta Prese objekta laukus failā,
   kas piesaistīts faila objektam fout. **/
void Prese::write(ostream &fout)
{
   fout.write((char *)this, sizeof(Prese)); /// Visa komponentes vērtība tiek ierakstīta
};
/** Metode read(fin) -
   nolasa Prese objekta laukus no faila,
   kas piesaistīts faila objektam fin,
   ieraksta nolasīto informāciju Prese objektā. **/
bool Prese::read(istream &fin)
{
   fin.read((char *)this, sizeof(Prese)); /// Visa komponentes vērtība tiek nolasīta
   return (bool)fin;
};
/** Metode print() -
   izdrukā Prese objekta laukus **/
void Prese::print()
{
   cout << "Preses nosaukums: " << nos << endl;
   cout << "Preses veids: " << veids << endl;
   cout << "Preses reizes skaits: " << reiz << endl;
   cout << "Preses valsts: " << val << endl;
   cout << "Izdevēja nosaukums: " << izdevejs << endl;
   cout << "Izdevēja indekss: " << izdIndx << endl;
   cout << endl;
};
