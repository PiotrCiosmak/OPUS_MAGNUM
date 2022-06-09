#include "Teksperyment.hpp"

using namespace std;

Teksperyment::Teksperyment()
{
    Tscyntylator *adr{new Tscyntylator{"scy01"}};
    detektor.push_back(adr);
    detektor.push_back(new Tscyntylator{"scy02"});
    detektor.push_back(new Tkomora{"kom01"});
    detektor.push_back(new Tkomora{"kom02"});
    detektor.push_back(new Tscyntylator_XY{"scyXY"});
}

Teksperyment::~Teksperyment()
{
    for (int i = 0; i < detektor.size(); ++i)
    {
        cout << detektor.at(i)->podaj_nazwe() << " destruktor:";
        delete detektor[i];
        cout << "\n";
    }
}

void Teksperyment::wypisz_konfiguracje()
{
    cout << "Biezaca konfiguracja detektorow eksperymentu:\n";
    for (int i = 0; i < detektor.size(); ++i)
    {
        cout << i << ") " << detektor.at(i)->podaj_nazwe() << ", ";
    }
    cout << "\n\n";
}

void Teksperyment::przed_petla_analizujaca()
{
    cout << "Funkcja Teksperyment::" << __func__ << "\n";
    string trzon_nazwy_plik("param");
    for (auto det: detektor)
        det->wczytaj_swoje_parametry(trzon_nazwy_plik);
}

void Teksperyment::analiza_zdarzenia_przez_detektor()
{
    for(auto det:detektor)
        det->analizuj_biezace_zdarzenie();
}

void Teksperyment::wyniki_pomiaru()
{
    cout<<"Funckja Teksperyment::wyniki_pomiaru"<<endl;
    for(auto det:detektor)
        det->zapisz_wyniki_analizy();
}