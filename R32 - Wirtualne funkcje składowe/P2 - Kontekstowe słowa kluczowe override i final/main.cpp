#include <iostream>
#include "Teksperyment.hpp"

using namespace std;

int main()
{
    cout << "Tu CERN, Rozpoczynamy eksperyment z ATLAS-em\n";

    Teksperyment atals;
    atals.wypisz_konfiguracje();
    atals.przed_petla_analizujaca();
    cout << "Rozpoczyna sie petla analizy kolejnych zdarzen\n";
    for (int z = 0; z < 6; ++z)
    {
        cout << "Zdarzenie nr = " << z << " ";
        atals.analiza_zdarzenia_przez_detektor();
        cout << "- obsluzone\n";
    }
    cout << "--- Po petli analizy kolenych zdarzen\n";
    atals.wyniki_pomiaru();
    cout << "--------Koniec programu pomiarow\n";
}