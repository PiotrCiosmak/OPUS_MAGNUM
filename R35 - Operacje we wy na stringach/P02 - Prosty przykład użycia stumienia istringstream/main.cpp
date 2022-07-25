#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    double wspolczynnik;
    string wyraz;
    int liczba_int;
    string tresc{"2157.15 wtorek 0x44"};
    istringstream param(tresc);

    param >> wspolczynnik;
    cout << "Wczytany wspolczynnik = " << wspolczynnik
         << " a podwojony = " << 2 * wspolczynnik << endl;

    param >> wyraz;
    cout << "Wczytany wyraz = " << wyraz << endl;

    param >> hex >> liczba_int;
    cout << "Wczytana (w zapisie hex) liczba_int = " << liczba_int << endl;

    cout << "To wczytalismy ze strumienia,\nktorego tresc to: [" << param.str() << "]" << endl;

    if (param.eof())
    {
        cout << "\nUwaga: Flaga ios::eofbit ustawiona!" << endl;
        param.clear(param.rdstate() & ~ios::eofbit);
    }

    param.seekg(1, ios::beg);
    char c;
    param.get(c);
    cout << "Wydobyty znak c = " << c << endl;

    param.seekg(7, ios::cur);
    param.get(c);
    cout << "Siodmy znak dalej to = " << c << endl;

    param.seekg(2);
    param >> wspolczynnik;
    cout << "Liczba wydobyta z fragmentu: " << wspolczynnik << endl;

    istringstream motto{"Honni soit qui mal y pense"};
    cout << "Zmienielismy tresc trumienia.\nTeraz jest to: " << motto.str();

    string cytat;
    getline(motto, cytat, 'q');
    cout << "\nWczytane: " << cytat << endl;

    motto >> wyraz;
    cout << "Wczytane: " << wyraz << endl;
}