#include "Tkomora.hpp"

using namespace std;

Tkomora::~Tkomora()
{
    cout << __func__ << ", ";
}

void Tkomora::wczytaj_swoje_parametry(string trzon_nazwy_pliku)
{
    string plik = trzon_nazwy_pliku + "_" + moja_nazwa + ".txt";
    cout << " " << moja_nazwa << ":Czytam parametry komory z pliku " << plik << "\n";
    //otwarcie pliku i odczyt
    //...
    wynik.clear();
}

void Tkomora::analizuj_biezace_zdarzenie()
{
    static double trajektoria_lotu_jonu;
    trajektoria_lotu_jonu += 3.57;
    wynik.push_back(trajektoria_lotu_jonu);
    cout << "%";
}

void Tkomora::zapisz_wyniki_analizy()
{
    cout << " " << moja_nazwa << " Zebrane wyniki pomiarowe tej komory\n";
    for (int nr = 0; nr < wynik.size(); ++nr)
    {
        cout << "|" << setw(4) << wynik.at(nr) << " ";
    }
    cout << "|\n";
}