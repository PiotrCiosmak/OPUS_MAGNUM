#include "Tmercedes.hpp"
#include <iostream>

using namespace std;

Tmercedes::Tmercedes(double x, int typ_motoru, double klim) : xxx{x}, Tsamochod(typ_motoru), casablanca(klim)
{
    cout << "\t\tKonstruktor Tmercedesa" << endl;
}

Tmercedes::~Tmercedes()
{
    cout << "\t\tDestruktor Tmercedesa" << endl;
}