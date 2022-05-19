#include <iostream>
#include "Tautomobil.hpp"

using namespace std;

ostream &operator<<(ostream &ekran, const Tautomobil &obj);

int main()
{
    Tautomobil mojfiacik{4, "bialy", 300000};
    mojfiacik.zmien_pozycje(10.0, 25.1);

    Tautomobil taksowka{mojfiacik}; //konstruktor kopiujący
    Tautomobil sluzbowy = mojfiacik; //konstruktor kopiujący

    taksowka.zmien_pozycje(7.3, 5.8);

    cout << "Lista istniejacych automobili\n"
         << "'mojfiacik'" << mojfiacik
         << "'taksowka'" << taksowka;

    Tautomobil dziwak(3, "bialy", 5000);
    cout << "Jeszcze jeden o nazwie 'dziwak'\n" << dziwak;

    dziwak = mojfiacik; //kopiujacy operator przypisania
    mojfiacik.zmien_pozycje(12, 12);

    cout << "'dziwak' po przypisaniu:\n" << dziwak << "a mojfiacik odjechal: " << mojfiacik;

    const Tautomobil muzealny{4, "czerwony", 25000};
    Tautomobil filmowy{muzealny}; //konstruktor kopiujacy

    dziwak = muzealny; //znowu przypisanie (kopiujace)

    filmowy.zmien_pozycje(3, 3);
    dziwak.zmien_pozycje(4, 4);
    cout << "Czy przypisanie 'od' obiektu const dziala?\n"
         << "'muzealny': " << muzealny << "'filmowy': " << filmowy << "'dziwak' po... " << dziwak;

    cout << "\n### Proby pracy z mechanizmem przenoszenia ########\n";
    Tautomobil autko{std::move(dziwak)};
    cout << "\nZrobione konstruktorem przenoszacym======\n"
         << "'autko': " << autko << "ogolocony 'dziwak' " << dziwak;

    dziwak = mojfiacik;
    dziwak.zmien_pozycje(4, 3);
    cout << "'dziwak': " << dziwak << "'mojfiacik': " << mojfiacik << endl;

    dziwak = std::move(mojfiacik);
    cout << "Po przypisaniu przenoszacym=====\n"
         << "'dziwak': " << dziwak << "'mojfiacik' = " << mojfiacik << endl;

    dziwak = std::move(muzealny);
    cout << "Po przypisaniu jakim?\n" << "'dziwak': " << dziwak << "'muzealny': " << muzealny << endl;
}

ostream &operator<<(ostream &ekran, const Tautomobil &obj)
{
    ekran << "\tkol " << obj.liczba_kol << ", przebieg " << obj.stan_licznika << ", kolor " << obj.kolor_karoserii;
    if (obj.tabl_gps)
        ekran << ", GPS[" << obj.tabl_gps[0] << ", " << obj.tabl_gps[1] << "]" << endl;
    else
        ekran << "\n\tUwaga: obiekt ma wymontowana tablce GPS!" << endl;
    return ekran;
}