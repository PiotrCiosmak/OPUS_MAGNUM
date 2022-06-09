#ifndef OPUS_MAGNUM_TSCYNTYLATOR_HPP
#define OPUS_MAGNUM_TSCYNTYLATOR_HPP

#include "Telement_pomiarowy.hpp"
#include <iostream>
#include <vector>
#include <iomanip>

class Tscyntylator : public Telement_pomiarowy
{
public:
    Tscyntylator(std::string n) : Telement_pomiarowy{n}
    {
        robocza_tablica = new int[4000]{0};
    }

    ~Tscyntylator() override
    {
        std::cout << __func__ << " (delete!),";
        delete[] robocza_tablica;
    }

    void wczytaj_swoje_parametry(std::string trzon_nazwy_pliku) override;

    void analizuj_biezace_zdarzenie() override;

    void zapisz_wyniki_analizy() final;

protected:
    int *robocza_tablica;
    std::vector<int> wynik;
};

#endif //OPUS_MAGNUM_TSCYNTYLATOR_HPP
