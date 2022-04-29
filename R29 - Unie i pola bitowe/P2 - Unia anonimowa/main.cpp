#include <iostream>

using namespace std;

//Unie anonimowe globalne muszą mieć przydomek static
static union
{
    int x;
};

int main()
{
    //Zmienne anonimowej uni wchodza w zakres zewnętrzy
    union
    {
        int licz;
        double wspolcz;
        char znak;
        int *wskaznik;
    };
    cout << "Odnoszenie sie do skladnikow uni anonimowej" << endl;
    licz = 4;
    cout << "(Unia anonimowa) licz = " << licz << endl << endl << endl;
    wspolcz = 6.66;
}