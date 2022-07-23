#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

void pomiar(string nazwa);

void odczyt(const char *nazwa);

int main()
{
    int nr_silnika{4};
    double temperatura{156.7123};
    ostringstream skomunikat;

    skomunikat << "Awaria silnika " << setw(2) << nr_silnika
               << ", temperatura oleju " << fixed << setprecision(2)
               << temperatura << " stopni C\n";
    if (!skomunikat)
        cout << "Jaki blad pracy strumienia" << endl;

    skomunikat.fill('.');
    skomunikat.width(25);
    skomunikat << "Musisz cos zrobic!!!\n";
    cout << "Aby sie przekonac, czy w strumieniu\n"
            "jest rzeczywiscie zadany tekst\n"
            "wypisujemy jego tresc na ekran\n"
            "*******************\n"
         << skomunikat.str()
         << "*******************\n";

    skomunikat.seekp(8, ios::beg);
    skomunikat << "XYZ";
    cout << "W takim stringu mozna nawet pozycjonowac wskaznik pisania:\n" << skomunikat.str();
    skomunikat.str("Nowa wstepna tresc niszczaca stara");
    cout << skomunikat.str() << endl;

    double pi{3.1415};
    skomunikat << pi;
    skomunikat << ", a dwa pi = " << 2 * pi;
    cout << skomunikat.str() << endl;

    cout << "\nDefiniujemy inny string, chcemy zbudowac nazwe jakiegos pliku" << endl;
    int nr_zestawu{167};
    int nr_dnia{9};
    int nr_miesiaca{5};
    int nr_roku{2019};
    ostringstream snazwa_pliku;
    snazwa_pliku << "Probka_"
                 << setfill('0') << setw(5) << nr_zestawu
                 << "_z_" << setw(2) << nr_dnia
                 << "_" << setw(2) << nr_miesiaca
                 << "_" << setw(4) << nr_roku
                 << ".dane";
    pomiar(snazwa_pliku.str());
    odczyt(snazwa_pliku.str().c_str());
}

void pomiar(string nazwa)
{
    cout << "Pomiar, a wynik zapisywany w pliku:\n" << nazwa << endl;
}

void odczyt(const char *nazwa)
{
    cout << "Odczyt pomiaru, zapisanego w pliku:\n" << nazwa << endl;
}