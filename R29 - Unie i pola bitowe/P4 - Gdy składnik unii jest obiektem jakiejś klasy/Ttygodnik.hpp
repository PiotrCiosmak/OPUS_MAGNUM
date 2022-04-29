#ifndef OPUS_MAGNUM_TTYGODNIK_HPP
#define OPUS_MAGNUM_TTYGODNIK_HPP

#include <iostream>

struct Ttygodnik
{
    int ile_stron;
    double cena;

    void opis()
    {
        std::cout << "tygodnik: " << ile_stron << " stron, cena " << cena << std::endl;
    }
};

#endif //OPUS_MAGNUM_TTYGODNIK_HPP
