#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void czytaj_40_liczb_int(ifstream &s);

void wypisz_biezace_ustawienia(ifstream &s);

int main()
{
    ifstream strum;
    string nazwa_pliku("t.tmp");
    strum.open(nazwa_pliku, ios::in);
    //czy się udało?
    if (!strum)
    {
        cout << "Blad otwarcia pliku: " << nazwa_pliku << endl;
        return -1;
    }
    wypisz_biezace_ustawienia(strum);
    cout << "Zmiana powodu rzucania wyjatku" << endl;
    strum.exceptions(ios::failbit | ios::badbit);
    wypisz_biezace_ustawienia(strum);
    try
    {
        czytaj_40_liczb_int(strum);
    }
    catch (ios::failure const &kapsula)
    {
        cout << "ios::failure. Nie udalo sie, informuje: " << kapsula.what() << endl;
    }
}

void czytaj_40_liczb_int(ifstream &s)
{
    for (int i = 0; i < 40; ++i)
    {
        int wartosc;
        s >> wartosc;
        cout << "(" << wartosc << ")";
    }
}

void wypisz_biezace_ustawienia(ifstream &s)
{
    cout << "Wyjatek bedzie rzucony, gdy ustawione sa flagi:\n";
    ios::io_state rzuc_gdy = s.exceptions();

    cout << "ios::failbit - ";
    if (rzuc_gdy & ios::failbit)
        cout << "TAK\n";
    else
        cout << "nie\n";

    cout << "ios::eofbit - ";
    if (rzuc_gdy & ios::eofbit)
        cout << "TAK\n";
    else
        cout << "nie\n";

    cout << "ios::badbit - ";
    if (rzuc_gdy & ios::badbit)
        cout << "TAK\n";
    else
        cout << "nie\n";

}