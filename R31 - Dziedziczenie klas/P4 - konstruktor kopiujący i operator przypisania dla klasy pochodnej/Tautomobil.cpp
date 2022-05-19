#include "Tautomobil.hpp"
#include <iostream>

using namespace std;

Tautomobil::Tautomobil(int kola, std::string kolor, int licznik) : Tpojazd(kola), stan_licznika{licznik},
                                                                   kolor_karoserii{kolor}
{}

//definicja konstruktora kopiującego dla klasy pochodnej
Tautomobil::Tautomobil(const Tautomobil &wzor) : Tpojazd(wzor), stan_licznika{0},
                                                 kolor_karoserii{kolor_karoserii = wzor.kolor_karoserii}
{}

//definicja konstruktora przenoszacego dla klasy pochodnej
Tautomobil::Tautomobil(Tautomobil &&zlom) : Tpojazd(std::move(zlom)), stan_licznika{0},
                                            kolor_karoserii{zlom.kolor_karoserii}
{}

//definicja kopiującego operatora przypisania dla klast pochodnej
Tautomobil &Tautomobil::operator=(const Tautomobil &wz)
{
    if (this != &wz)
    {
        Tpojazd::operator=(wz);
        kolor_karoserii = wz.kolor_karoserii;
        stan_licznika = wz.stan_licznika + 2;
    }
    return *this;
}

//definicja przenoszącego operatora przypisania klasy pochodnej
Tautomobil &Tautomobil::operator=(Tautomobil &zlom)
{

    if(this != &zlom)
    {
        Tpojazd::operator=(std::move(zlom));
        kolor_karoserii=zlom.kolor_karoserii;
        stan_licznika=zlom.stan_licznika+2;
    }
    return *this;
}