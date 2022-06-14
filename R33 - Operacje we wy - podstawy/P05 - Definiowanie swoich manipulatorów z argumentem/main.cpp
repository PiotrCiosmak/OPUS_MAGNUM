#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class TnaszManip
{
public:
    TnaszManip(int argument) : arg{argument}
    {}

    void dzialaj(ostream &os)
    {
        os << setw(arg);
    }

private:
    int arg;
};

ostream &operator<<(ostream &strum, TnaszManip man)
{
    man.dzialaj(strum);
    return strum;
}

int main()
{
    string nazwa("Musee d'Orsay");

    cout << "#" << nazwa << "#\n";
    cout << "#" << TnaszManip(18) << nazwa << "#\n";
}