#ifndef OPUS_MAGNUM_TMAGAZYN_HPP
#define OPUS_MAGNUM_TMAGAZYN_HPP

#include <iostream>

struct Tmagazyn
{
public:
    enum Tco_w_unii
    {
        nic, mamy_litere, mamy_liczbe
    };
    Tco_w_unii co_przechowujemy;

    Tmagazyn()
    {
        co_przechowujemy = nic;
    }

    void magazyn_ma();

    void wstaw(char z);

    void wstaw(double x);

private:
    union
    {
        char litera;
        double liczba;
    };
};

#endif //OPUS_MAGNUM_TMAGAZYN_HPP
