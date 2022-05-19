#include "Tpojazd.hpp"
#include <iostream>

using namespace std;

Tpojazd::Tpojazd(const Tpojazd &wzor) //konstruktor kopiujący
{
    liczba_kol = wzor.liczba_kol;
    tabl_gps = new double[ile_wspolrzednych];
    for (int nr = 0; nr < ile_wspolrzednych; ++nr)
        tabl_gps[nr] = wzor.tabl_gps[nr];
}

Tpojazd::Tpojazd(Tpojazd &&zlom) //konstruktor przenoszący
{
    liczba_kol = zlom.liczba_kol;
    tabl_gps = zlom.tabl_gps;
    zlom.tabl_gps = nullptr;
}

Tpojazd &Tpojazd::operator=(const Tpojazd &wz) //kopiujący operator=
{
    if (this != &wz)
    {
        delete[] tabl_gps;
        liczba_kol = wz.liczba_kol;
        tabl_gps = new double[ile_wspolrzednych];
        for (int nr = 0; nr < ile_wspolrzednych; ++nr)
            tabl_gps[nr] = wz.tabl_gps[nr];
    }
    return *this;
}

Tpojazd &Tpojazd::operator=(Tpojazd &&odzysk)
{
    cout << "Dziala przenoszacy operator= Tpojazd" << endl;
    if (this != &odzysk)
    {
        delete[] tabl_gps;
        liczba_kol = odzysk.liczba_kol;
        tabl_gps = odzysk.tabl_gps;
        odzysk.tabl_gps = nullptr;
    }
    return *this;
}