#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string tekst{"Coz, wedlug Ben-Alego,\n"
                 "czarnomistrza Krakowa\n"
                 "nie jest to nic wielkiego\n"
                 "dorozke zaczarokowac."};

    //Otwieramy istniejący plik i go zerujemy, a jeśli go nie ma - tworzymy go
    fstream strum("wiersz.txt", ios::trunc | ios::in | ios::out);
    if (!strum)
    {
        cout << "Blad otwarcia pliku" << endl;
        return -1;
    }
    strum << tekst;
    strum.seekp(25);
    strum << "ABCDE";
    strum.seekp(-6, ios::end);
    strum << "X";
}