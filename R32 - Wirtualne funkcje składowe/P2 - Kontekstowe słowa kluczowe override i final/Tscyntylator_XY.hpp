#ifndef OPUS_MAGNUM_TSCYNTYLATOR_XY_HPP
#define OPUS_MAGNUM_TSCYNTYLATOR_XY_HPP

#include "Tscyntylator.hpp"
#include <iostream>

class Tscyntylator_XY : public Tscyntylator
{
public:
    Tscyntylator_XY(std::string n) : Tscyntylator{n}
    {}

    ~Tscyntylator_XY()
    { std::cout << __func__ << ", "; }

    void wczytaj_swoje_parametry(std::string trzon_nazwy_pliku) override
    { std::cout << " " << moja_nazwa << ":Czytam parametry scyntylatoraXY\n"; }

    void analizuj_biezace_zdarzenie() override;

    //void zapisz_wyniki_analizty() override //Błąd, bo w klasie Tscyntylator był final
};


#endif //OPUS_MAGNUM_TSCYNTYLATOR_XY_HPP
