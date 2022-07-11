#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class TnaszManip
{
public:
    TnaszManip(int argument) : arg{argument}
    {}

    void dzialaj(ostream &os) const
    {
        os << setw(arg);
    }

private:
    int arg;
};

ostream &operator<<(ostream &strum, TnaszManip const &man)
{
    man.dzialaj(strum);
    return strum;
}

/*
ostream &operator<<(ostream &strum, TnaszManip &&man)
{
    man.dzialaj(strum);
    return strum;
}
*/

int main()
{
    double wartosc = 36.6;
    TnaszManip styl_temp(12);
    TnaszManip styl_gest(25);

    cout << "[" << styl_temp << wartosc << "],\n"
         << "[" << styl_gest << wartosc << "] \n"
         << "[" << TnaszManip(7) << wartosc << "]" << endl;
}