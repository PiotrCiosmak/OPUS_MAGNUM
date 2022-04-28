#ifndef OPUS_MAGNUM_TWEKTOREK_DZIEDZ_HPP
#define OPUS_MAGNUM_TWEKTOREK_DZIEDZ_HPP

#include <iostream>
#include "Twektorek.hpp"

class Twektorek_dziedz : public Twektorek
{
public:
    Twektorek_dziedz(double a = 0, double b = 0, double c = 0) : Twektorek(a, b, c)
    {
        std::cout << "\tKonstruktor kl.POCHODNEJ Twektorek_dziedz, x=" << x << ", y=" << y << ", z=" << z << std::endl;
    }

    virtual ~Twektorek_dziedz()
    {
        std::cout << "\tDestruktor kl. POCHODNEJ Twektorek_dziedz" << std::endl;
    }

private:
    int wypelniacz[1000];
};

#endif //OPUS_MAGNUM_TWEKTOREK_DZIEDZ_HPP
