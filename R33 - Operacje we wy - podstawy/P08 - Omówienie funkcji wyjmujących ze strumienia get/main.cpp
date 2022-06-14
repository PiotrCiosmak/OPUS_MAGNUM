#include <iostream>

using namespace std;

int main()
{
    char imie[7],
            nazwisko[20],
            c;
    cout << "Podaj swoje imie:";
    cin.get(imie, 7);
    cout << "Podales -->" << imie
         << "\nteraz nazwisko:";
    cin.get(nazwisko, 20, 's');
    cout << "\nNazwisko brzmi -->" << nazwisko << endl;
    cout << "przyjecie jeszcze jednego znaku:";
    cin.get(c);
    cout << "\nKolejny wczytany znak -->" << c << endl;
}