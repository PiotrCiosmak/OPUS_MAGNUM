#ifndef OPUS_MAGNUM_TMERCEDES_HPP
#define OPUS_MAGNUM_TMERCEDES_HPP

#include "Tsamochod.hpp"
#include "Tklimatyzacja.hpp"

class Tmercedes : public Tsamochod
{
public:
    Tmercedes(double x, int typ_motoru, double klim);

    ~Tmercedes();

protected:
    double xxx;
    Tklimatyzacja casablanca;
};


#endif //OPUS_MAGNUM_TMERCEDES_HPP
