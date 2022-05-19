#include "Tklimatyzacja.hpp"
#include <iostream>

using namespace std;

Tklimatyzacja::Tklimatyzacja(double t) : temperatura(t)
{
    cout << "\t\tKonstruktor klimatyzacji (skladnik mercedesa)" << endl;
}

Tklimatyzacja::~Tklimatyzacja()
{
    cout << "\t\tDestruktor klimatyzacji (skladnik mercedesa)" << endl;
}