#ifndef OPUS_MAGNUM_TKOMORA_HPP
#define OPUS_MAGNUM_TKOMORA_HPP

#include <iostream>
#include <vector>
#include "Telement_pomiarowy.hpp"
#include <iomanip>

class Tkomora final : public Telement_pomiarowy
{
public:
    Tkomora(std::string nazwa) : Telement_pomiarowy{nazwa}
    {}

    ~Tkomora() override;

    void wczytaj_swoje_parametry(std::string trzon_nazwy_pliku) override;

    void analizuj_biezace_zdarzenie() override;

    void zapisz_wyniki_analizy() override;

private:
    std::vector<double> wynik;
};

#endif //OPUS_MAGNUM_TKOMORA_HPP
