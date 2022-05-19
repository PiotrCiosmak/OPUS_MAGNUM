#include <iostream>
#include "Tmercedes.hpp"

using namespace std;

int main()
{
    {
        cout << "Kreacja obiektu klasy Tsamochod" << endl;
        Tsamochod czatny(500);
        cout << "\nobikekt czatny samochod istnieje\nteraz bedzie likwidowany!\n\n";
    }
    cout << "obiekt Tsamcohod zlikwidowany\n\n";
    {
        cout << "Kreacja obiektu klasy Tmercedes\n";
        Tmercedes popielaty(6.5, 1200, 22.5);
        cout << "obiekt Tmercedes istnieje\nteraz bedzie likwidowany!\n";
    }
    cout << "obiket Tmercedes zlikwidowany";
}