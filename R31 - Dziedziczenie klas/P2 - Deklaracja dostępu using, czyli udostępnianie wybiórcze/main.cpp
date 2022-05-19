#include <iostream>

using namespace std;

class przodek
{
public:
    int szer;

    double *funpubl(int m);

protected:
    int n;
    double x;

    void funprot(double *, int &);
};

//Dziedziczymy prywatnie lecz zmianiamy dostęp niektórych składników na protected lub public

class potomek : private przodek
{
    //...
public:
    using przodek::szer;
    using przodek::funpubl;
protected:
    using przodek::x;
    using przodek::funprot;
};

int main()
{

}