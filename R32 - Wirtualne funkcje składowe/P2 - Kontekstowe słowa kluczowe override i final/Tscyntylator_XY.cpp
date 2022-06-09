#include "Tscyntylator_XY.hpp"

using namespace std;

void Tscyntylator_XY::analizuj_biezace_zdarzenie()
{
    //siegniecie do innych rejestrów interfejsu
    static int fikcyjna_wartosc;
    wynik.push_back(fikcyjna_wartosc);
    cout << "#";
}