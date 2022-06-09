#include "Tscyntylator.hpp"

using namespace std;

void Tscyntylator::wczytaj_swoje_parametry(string trzon_nazwy_pliku)
{
    string plik = trzon_nazwy_pliku + "_" + moja_nazwa + ".txt";
    cout << " " << moja_nazwa << ":Czytam parametry scyntylatora z pliku " << plik << "\n";
    //...
    //Przy okazcji przygotowanie do pętli pomiarowej
    wynik.clear();
}

void Tscyntylator::analizuj_biezace_zdarzenie()
{
    static int wartosc;
    wartosc += 27;
    wartosc %= 100;
    wynik.push_back(wartosc);
    cout << "*";
}

void Tscyntylator::zapisz_wyniki_analizy()
{
    cout << "Zzebrane wyniki pomiarowe tego scyntylatora " << moja_nazwa << "\n";
    for (auto w: wynik)
        cout << setw(6) << w << " ";
    cout << "\n";
}