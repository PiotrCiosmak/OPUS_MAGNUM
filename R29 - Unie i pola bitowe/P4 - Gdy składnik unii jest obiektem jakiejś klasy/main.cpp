#include <iostream>
#include "Ttygodnik.hpp"

using namespace std;

union Umagazyn
{
    char litera;
    Ttygodnik gazeta;

    void fun()
    {
        cout << "rozmiar tej unii to: " << sizeof(*this) << " bajtow" << endl;
    }

    void wstaw_tygodnik(int stron, double zl)
    {
        gazeta.ile_stron = stron;
        gazeta.cena = zl;
    }
};

int main()
{
    Umagazyn przechowalnia;
    przechowalnia.fun();

    przechowalnia.litera = 'S';
    cout << "Obecnie przechowywana litera to '" << przechowalnia.litera << "'" << endl;

    przechowalnia.gazeta.ile_stron = 16;
    przechowalnia.gazeta.cena = 12.5;
    przechowalnia.gazeta.opis();

    przechowalnia.litera = 'M';
    cout << "Obecnie przechowywana litera to '" << przechowalnia.litera << "'" << endl;

    przechowalnia.wstaw_tygodnik(5, 4.6);
    przechowalnia.gazeta.opis();

    cout << "Definiujemy drugi obiekt Umagazyn" << endl;
    Umagazyn drugi = przechowalnia;
    cout << "Od nowisci w kopii jest";
    drugi.gazeta.opis();

    przechowalnia.wstaw_tygodnik(80, 25.0);
    cout << "Po zwyklym przypisaniu.";
    drugi = przechowalnia; //autom. generowany operator przypisania w unii
    drugi.gazeta.opis();
}