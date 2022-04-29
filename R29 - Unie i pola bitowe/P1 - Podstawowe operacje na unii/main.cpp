#include <iostream>

using namespace std;

union Tskarbiec//Unia ta ma rozmiar odpowiadający rozmiarowi największego skladnika (long 8 bajtów)
{
    //Domniemane public:
    int in;
    long ln;
    char zn;
};

void funk(char);

int main()
{
    cout << "Podstawowe operacje na Uni" << endl;
    Tskarbiec pudelko;
    pudelko.in = 5;
    cout << "pudelko.in = " << pudelko.in << endl;

    pudelko.zn = 'm'; //licza 5 w zmiennej in zostaje zniszczona
    cout << "pudelko.zn = " << pudelko.zn << endl;
    //cout << "Błędnie: pudelko.in = " << pudelko.in << endl;

    char c = pudelko.zn;
    funk(pudelko.zn);

    Tskarbiec *wsk;
    wsk = &pudelko;
    wsk->ln = 654321;
}

void funk(char)
{
    return;
}