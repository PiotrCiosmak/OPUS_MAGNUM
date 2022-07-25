#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

bool szukacz(istringstream &s, string etykieta, double &zmienna);

int main()
{
    istringstream nastawy(
            R"(Czynnik zyromagnetyczny 3.4
wzmocnienie 72.6 decybele
kwota_wplaty 237500
wspolczynnik_kalibracji 0.34 0.92 0.1
powiekszenie_mikroskopu 580 x)"
    );

    double x;

    string etykieta("powiekszenie_mikroskopu");
    cout << "\nPrzeczytamy teraz liczbe" << endl;
    if (szukacz(nastawy, etykieta, x))
        cout << "a) " << etykieta << " = " << x << endl;

    cout << "\nPrzeczytamy teraz inna liczbe" << endl;
    if (szukacz(nastawy, "zyromagnetyczny", x))
        cout << "b) x = " << x << endl;

    cout << "\nPrzeczytamy teraz inna liczbe" << endl;
    if (szukacz(nastawy, "modul Younga", x))
        cout << "c) x = " << x << endl;
    else
        cout << "Niewczytane, moze to byl parametr opcjonalny?\n";

    vector<double> factor;
    cout << "\nPrzeczytamy teraz inna liczbe" << endl;
    if (szukacz(nastawy, "wspolczynnik_kalibracji", x))
    {
        cout << "d) x = " << x << endl;
        factor.push_back(x);
        while (nastawy >> x)
            factor.push_back(x);
        for (auto y: factor)
            cout << " " << y;
        cout << endl;

        //strumien jest w stanie bledu fail, bo próbowałem czytać liczby do skutku
        if (nastawy.fail())
            nastawy.clear(nastawy.rdstate() & ~ios::failbit);
        //moglo sie to zdarzyć na samym końcu pliku, więc
        if (nastawy.eof())
            nastawy.clear(nastawy.rdstate() & ~ios::eofbit);

        if (szukacz(nastawy, "wzmocnienie", x))
            cout << "e) wzmocnienie = " << x << endl;
    }
}

bool szukacz(istringstream &s, string etykieta, double &zmienna)
{
    string tr{s.str()};
    size_t nr{tr.find(etykieta)};
    if (nr == string::npos)
    {
        cout << "Blad: Nazwa danej (etykieta) >" << etykieta << " nie znaleziona" << endl;
        return false;
    }
    cout << "Etykieta [" << etykieta << "] znaleziona na pozycji " << nr << endl;

    s.seekg(nr + etykieta.length());
    double wartosc;
    s >> wartosc;
    if (!s)
    {
        cout << "Blad wczytywania wartosci po etykiecie " << etykieta << endl;
        return false;
    }
    else
    {
        cout << "Za nia jest wartosc " << wartosc << endl;
        zmienna = wartosc;
        return true;
    }
}