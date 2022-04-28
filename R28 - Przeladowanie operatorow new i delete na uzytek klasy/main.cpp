#include <iostream>
#include "Twektorek.hpp"

using namespace std;

int main()
{
    try
    {
        Twektorek *w1;
        w1 = new Twektorek{1, 1, 1};
        w1->wypisz();
        delete w1;
    }
    catch (bad_alloc &e)
    {
        cout << "Zlapany obiekt wyjatku klast std::alloc" << endl;
    }
    //Wytwarzanie obiektu korzystając ze standardowych operatorów new i delete
    cout << "\nRezerwacja operatorem new globalnym..." << endl;
    Twektorek *w2 = ::new Twektorek{2, 2, 2};
    w2->wypisz();
    ::delete w2;
    cout << "Po skasowaniu w1 (globalnym delete)\n" << endl;

    //rezerwacja tablicy obiektów
    Twektorek* wtab = new Twektorek[3];
    for(int i =0; i<3; ++i)
    {
        wtab[i].wypisz()
    }
    delete[] wtab;
}