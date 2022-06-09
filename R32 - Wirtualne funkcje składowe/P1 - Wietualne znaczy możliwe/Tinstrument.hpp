#ifndef OPUS_MAGNUM_TINSTRUMENT_HPP
#define OPUS_MAGNUM_TINSTRUMENT_HPP

#include <iostream>

using namespace std;

class Tinstrument
{
public:
    virtual void wydaj_dzwiek()
    {
        cout << "Nieokreslony brzdek!\n";
    }

private:
    int cena;
};

class Ttrabka : public Tinstrument
{
public:
    void wydaj_dzwiek()
    {
        cout << "Tra=ta=ta!\n";
    }
};

class Tbeben : public Tinstrument
{
public:
    void wydaj_dzwiek()
    {
        cout << "Bum-bum-bum!\n";
    }
};

class Tfortepian : public Tinstrument
{
public:
    void wydaj_dzwiek()
    {
        cout << "Plim-plim-plim!\n";
    }
};

#endif //OPUS_MAGNUM_TINSTRUMENT_HPP
