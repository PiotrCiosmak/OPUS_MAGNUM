#include <iostream>

using namespace std;

class TSamochod
{
public:
    int rok_produkcji;

    virtual void rzecznik(ostream &strum);
};

class TMercedes : public TSamochod
{
public:
    string model;

    void rzecznik(ostream &strum) override;
};

//realizacja operatora << dla klasy podstawowej
ostream &operator<<(ostream &strum, TSamochod &x)
{
    x.rzecznik(strum);
    return strum;
}

//realizacje funkcji wirtualnych
void TSamochod::rzecznik(ostream &strum)
{
    strum << rok_produkcji;
}

void TMercedes::rzecznik(ostream &strum)
{
    TSamochod::rzecznik(strum);
    strum << " " << model;
}

int main()
{
    TSamochod a,b;
    a.rok_produkcji=2015;
    b.rok_produkcji=2017;

    TMercedes m;
    m.rok_produkcji=2016;
    m.model = "CLS";
    cout<<a<<"\n";
    cout<<b<<"\n";
    cout<<m<<"\n";
}