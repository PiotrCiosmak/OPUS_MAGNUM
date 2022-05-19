#ifndef OPUS_MAGNUM_TAUTOMOBIL_HPP
#define OPUS_MAGNUM_TAUTOMOBIL_HPP

#include "Tpojazd.hpp"
#include <string>

class Tautomobil : public Tpojazd
{
    friend std::ostream &operator<<(std::ostream &ekran, const Tautomobil &obj);

public:
    Tautomobil(int kola, std::string kolor, int licznik);

    //Mechanizm kopiowania obiektów realizuje ponizsze funkcje
    Tautomobil(const Tautomobil &wzor);

    Tautomobil &operator=(const Tautomobil &wz);

    //Mechanizm przenoszenia realizują
    Tautomobil(Tautomobil &&zlom);

    Tautomobil &operator=(Tautomobil &&zlom);

private:
    int stan_licznika;
    std::string kolor_karoserii;
};

#endif //OPUS_MAGNUM_TAUTOMOBIL_HPP
