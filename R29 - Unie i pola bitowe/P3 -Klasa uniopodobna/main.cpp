#include <iostream>
#include "Tmagazyn.hpp"

using namespace std;

int main()
{
    cout << "Klasa uniopodobna" << endl;
    Tmagazyn mag;
    mag.magazyn_ma();
    mag.wstaw('S');
    mag.magazyn_ma();
    mag.wstaw(6.28);
    mag.magazyn_ma();
}