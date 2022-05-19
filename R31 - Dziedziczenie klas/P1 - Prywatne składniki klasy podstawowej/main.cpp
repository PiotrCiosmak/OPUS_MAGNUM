#include <iostream>

using namespace std;

class Tryba
{
public:
    int pubs;

    void wstaw(int m)
    { this->a = m; }

    int czytaj()
    { return this->a; }

protected:
    int prots;
private:
    int a;
};

class Trekin : public Tryba
{
public:
    void funk();

private:
    double x;
};

void Trekin::funk()
{
    x = 15.6;
    //a=6; //tak sie nie da, ale...
    wstaw(6);
    cout << "Wyjety funkcja 'czytaj' skladnik a = " << czytaj() << endl;

    prots = 77;
    pubs = 100;
    cout << "Bezposrednio odczytany skladnik protected = " << prots << endl;
    cout << "Bezposrednio odczytany skladnik public = " << pubs << endl;
}

int main()
{
    Trekin wacek;
    wacek.funk();
}