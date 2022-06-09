#ifndef OPUS_MAGNUM_TEKSPERYMENT_HPP
#define OPUS_MAGNUM_TEKSPERYMENT_HPP

#include <iostream>
#include <vector>
#include "Telement_pomiarowy.hpp"
#include "Tscyntylator.hpp"
#include "Tkomora.hpp"
#include "Tscyntylator_XY.hpp"

class Teksperyment
{
public:
    Teksperyment();

    ~Teksperyment();

    void wypisz_konfiguracje();

    void przed_petla_analizujaca();

    void analiza_zdarzenia_przez_detektor();

    void wyniki_pomiaru();

private:
    std::vector<Telement_pomiarowy *> detektor;
};


#endif //OPUS_MAGNUM_TEKSPERYMENT_HPP
