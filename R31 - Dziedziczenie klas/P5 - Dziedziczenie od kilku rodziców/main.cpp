#include <iostream>

using namespace std;

class Tsamochod
{
public:
    Tsamochod(int arg) : a{arg}
    {
        cout << "Konstruktor Tsamochodu\n";
    }

protected:
    int a;
};

class Tlodka
{
public:
    Tlodka(int x) : b{x}
    {
        cout << "Konstruktor Tlodki\n";
    }

protected:
    int b;
};

class Tamfibia : public Tsamochod, public Tlodka
{
public:
    Tamfibia() : Tsamochod{1991}, Tlodka{4}
    {
        cout << "Konstruktor Tamfibii\n";
    }

    void pisz_skladniki()
    {
        cout << "Oto odziedziczone skladniki\na = " << a << "\nb = " << b << endl;
    }
};

int main()
{
    Tamfibia aaa;
    aaa.pisz_skladniki();
}