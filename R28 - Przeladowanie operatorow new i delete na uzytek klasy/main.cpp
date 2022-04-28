#include <iostream>
#include "Twektorek.hpp"
#include "Twektorek_dziedz.hpp"

using namespace std;

void niepowodzenie();

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
    try
    {
        cout << "\nRezerwacja operatorem new globalnym..." << endl;
        Twektorek *w2 = ::new Twektorek{2, 2, 2};
        w2->wypisz();
        ::delete w2;
        cout << "Po skasowaniu w1 (globalnym delete)\n" << endl;
    }
    catch (bad_alloc &e)
    {
        cout << "Zlapany obiekt wyjatku klast std::alloc" << endl;
    }

    //rezerwacja tablicy obiektów
    try
    {
        Twektorek *wtab = new Twektorek[3];
        for (int i = 0; i < 3; ++i)
        {
            wtab[i].wypisz();
        }
        delete[] wtab;
    }
    catch (bad_alloc &e)
    {
        cout << "Zlapany obiekt wyjatku klast std::alloc" << endl;
    }

    //wskaźnik = new (argumenty dodatkowe operatora) Twektorek{argumenty konstruktora};
    try
    {
        Twektorek *w3 = new(true) Twektorek{3, 33, 333};
        w3->wypisz();
        delete w3;
    }
    catch (bad_alloc &e)
    {
        cout << "Zlapany obiekt wyjatku klast std::alloc" << endl;
    }

    try
    {
        Twektorek *w4 = new(3.14, 100) Twektorek{4, 4, 4};
        w4->wypisz();
        delete w4;
    }
    catch (bad_alloc &e)
    {
        cout << "Zlapany obiekt wyjatku klast std::alloc" << endl;
    }


    //DRUGA CZESC ODNOŚNIE: OPERATORÓW NEW I DELETE ODZIEDZICZONYCH OD KLASY POCHODNIEJ
    cout << "\n\nDRUGA CZESC ODNOŚNIE: OPERATORÓW NEW I DELETE ODZIEDZICZONYCH OD KLASY POCHODNIEJ\n\n";

    cout << "Proba uzycia operator new dla klasy pochodnej Twektorek_dziedz..." << endl;
    Twektorek_dziedz *w5 = new Twektorek_dziedz{5, 55, 555};
    w5->wypisz();
    delete w5;

    //POLIMORFIZM
    cout << "\nAdres obiektu klasy pochodnej przypisany wskaźnikowi do kl. podstawowej" << endl;
    Twektorek *wpodst = new Twektorek_dziedz{6, 66, 666};
    wpodst->wypisz();
    delete wpodst;

    //Tworzenie i likwidowanie tablicy obiektów klasy pochodnej
    cout << "\nOperatorem new[] z klasy pochodnej Twektorek_dziedz..." << endl;
    Twektorek_dziedz *w6 = new Twektorek_dziedz[2];
    for (int i = 0; i < 2; ++i)
    {
        w6[i].wypisz();
    }
    delete[]w6;

    //Operatory new, które nie rzucą wyjątku std::bad_alloc
    cout << "\n\n---------To samo dla operatorow nierzucajacych wyjatkow" << endl;
    {//otwarce lokalnego bloku, żeby nie trzeba było zmieniać nazw wskaźników
        Twektorek *w1 = new(nothrow) Twektorek{20, 21, 22};
        if (w1 == nullptr) niepowodzenie();
        else w1->wypisz();
        delete[]w1;
        //W taki sposób jak wyżej można wykonac wszystkie rezerwacje i usuwanie obiektów przy braku rzucania wyjątków
    }
}

void niepowodzenie()
{
    cout << "Porazka w rezerwacji (konstruktor wiec nie wystartowal)" << endl;
}