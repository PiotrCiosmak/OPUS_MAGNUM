#ifndef OPUS_MAGNUM_TSAMOCHOD_HPP
#define OPUS_MAGNUM_TSAMOCHOD_HPP

#include "Tsrodek_transportu.hpp"
#include "Tsilnik.hpp"

class Tsamochod : public Tsrodek_transportu
{
public:
    Tsamochod(int typ_silnika);

    ~Tsamochod();

protected:
    int aa;
    Tsilnik jego_silnik;
};


#endif //OPUS_MAGNUM_TSAMOCHOD_HPP
