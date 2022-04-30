#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Funkcje orzekające
bool czy_nieparzyste_Fcja(int liczba);

bool czy_wieksza_niz_9_Fcja(int liczba);

//Dwie klasy obiektów funkcyjnych
class Tfunktator_czy_nieparzyste
{
public:
    bool operator()(int liczba)
    {
        return (liczba % 2);
    }
};

class Tfunktator_wieksze_niz
{
public:
    //konstruktor
    Tfunktator_wieksze_niz(int p) : porown{p}
    {}

    bool operator()(int liczba)
    {
        return (liczba > porown);
    }

private:
    //wartość progowa
    int porown;
};

int main()
{
    vector<int> v{4, 2, 13, 11, 5, 24, 7};
    cout << "Korzystamy z funkcji bibliotecznych count_if" << endl;
    auto pocz = v.begin();
    auto kon = v.end();

    int ile = count_if(pocz, kon, czy_nieparzyste_Fcja);
    cout << "Fun. orzekajaca: nieparzystych liczb jest" << ile << endl;

    ile = count_if(pocz, kon, czy_wieksza_niz_9_Fcja);
    cout << "Fun. orzekajaca: liczb > 9 jest" << ile << endl;

    cout << "\nInny sposob przeslania kryterium - obiektem funkcyjnym" << endl;
    ile = count_if(pocz, kon, Tfunktator_czy_nieparzyste());
    cout << "Obj. funkcyjny: nieparzystych liczb jest " << ile << endl;

    ile = count_if(pocz, kon, Tfunktator_wieksze_niz(9));
    cout << "Obj. funkcyjny: liczb > 9 jest " << ile << endl;

    ile = count_if(pocz, kon, Tfunktator_wieksze_niz(5));
    cout << "Obj. funkcyjny: liczb > 5 jest" << ile << endl;
}

bool czy_nieparzyste_Fcja(int liczba)
{
    return (liczba % 2);
}

bool czy_wieksza_niz_9_Fcja(int liczba)
{
    return (liczba > 9);
}