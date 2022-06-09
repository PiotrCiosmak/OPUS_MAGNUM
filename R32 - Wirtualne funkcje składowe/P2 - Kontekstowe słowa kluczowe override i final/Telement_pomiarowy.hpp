#ifndef OPUS_MAGNUM_TELEMENT_POMIAROWY_HPP
#define OPUS_MAGNUM_TELEMENT_POMIAROWY_HPP

#include <iostream>

class Telement_pomiarowy
{
public:
    Telement_pomiarowy(std::string naz) : moja_nazwa{naz}
    {};

    virtual ~Telement_pomiarowy()
    {
        std::cout << __func__;
    }

    virtual void wczytaj_swoje_parametry(std::string trzon_nazwy_pliku)
    {};

    virtual void analizuj_biezace_zdarzenie()
    {};

    virtual void zapisz_wyniki_analizy()
    {};

    std::string podaj_nazwe()
    { return moja_nazwa; };
protected:
    std::string moja_nazwa;
};

#endif //OPUS_MAGNUM_TELEMENT_POMIAROWY_HPP
