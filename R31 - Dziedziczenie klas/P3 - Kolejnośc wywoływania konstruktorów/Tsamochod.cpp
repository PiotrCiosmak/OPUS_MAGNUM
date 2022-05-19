#include "Tsamochod.hpp"
#include <iostream>

using namespace std;

Tsamochod::Tsamochod(int typ_silnika) : Tsrodek_transportu(), jego_silnik(typ_silnika)
{
    cout << "\tKonstruktor Tsamochod" << endl;
}

Tsamochod::~Tsamochod()
{
    cout << "\tDestruktor Tsamochod" << endl;
}