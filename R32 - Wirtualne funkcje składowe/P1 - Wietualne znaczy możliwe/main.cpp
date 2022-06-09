#include <iostream>
#include "Tinstrument.hpp"

using namespace std;

void muzyka(Tinstrument &powierzony_instrument);

int main()
{
    Tinstrument jakis_instrument;
    Ttrabka zlota_trabka;
    Tfortepian steinway_giseli;
    Tbeben moj_werbel;

    cout << "Zwykle wywolanie funkcji skladowych\n"
            "na rzecz obiektow - jak dotad nic szczegolnego\n";

    jakis_instrument.wydaj_dzwiek();
    zlota_trabka.wydaj_dzwiek();
    steinway_giseli.wydaj_dzwiek();
    moj_werbel.wydaj_dzwiek();

    cout << "Wywolanie funkcji na rzecz obiektu\n"
            "pokazywanego wskaznikiem instrumentu\n";

    Tinstrument *wskinstr;

    wskinstr = &jakis_instrument;
    wskinstr->wydaj_dzwiek();

    cout << "Rewelacja okazuje sie przy pokazaniu wskanikiem\n"
            "do instrumentow na obiekt klasy pochodnej od klasy Tinstrument!\n";

    wskinstr = &zlota_trabka;
    wskinstr->wydaj_dzwiek();

    wskinstr = &steinway_giseli;
    wskinstr->wydaj_dzwiek();

    wskinstr = &moj_werbel;
    wskinstr->wydaj_dzwiek();

    cout << "Podobne zachowanie jest takze\n"
            "w stosunku do referencji\n";

    muzyka(jakis_instrument);
    muzyka(zlota_trabka);
    muzyka(steinway_giseli);
    muzyka(moj_werbel);

    cout << "Orkiestra instrumentow zagra koncert\n";
    Tinstrument *orkiestra[] = {&zlota_trabka, &moj_werbel, &steinway_giseli, &moj_werbel, &zlota_trabka};
    for (int i = 0; i < 4; ++i)
    {
        orkiestra[i]->wydaj_dzwiek();
    }
}

void muzyka(Tinstrument &powierzony_instrument)
{
    powierzony_instrument.wydaj_dzwiek();
}