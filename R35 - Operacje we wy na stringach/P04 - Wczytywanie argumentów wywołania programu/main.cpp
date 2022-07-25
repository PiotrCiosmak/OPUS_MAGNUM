#include <iostream>
#include <sstream>

using namespace std;

void info()
{
    cout << "INFO: Program nalezy wowolac z 3 argumentami: [liczba] [wybor] [arg3]\n"
            "gdy [wybor] ma wartosc '-port to [arg3] jest numerem portu\n"
            "gdy [wybor] ma wartosc -file to [arg3] jest nazwa plik\n";
}

int main(int argc, char *argv[])
{
    cout << "Program " << argv[0] << "\nma argumentow: " << argc - 1 << endl;
    if (argc < 4)
    {
        cout << "Blad: za malo argumentow wywolania programu\n";
        info();
        return 5;
    }
    cout << "Oto argumenty przeslane do programu\n";
    for (int i = 0; i < argc; ++i)
        cout << "argv[" << i << "] " << argv[i] << endl;

    string wszystkie_parametry;
    for (int i = 1; i < argc; ++i)
    {
        wszystkie_parametry += argv[i];
        wszystkie_parametry += " ";
    }

    istringstream sp(wszystkie_parametry);
    sp.exceptions(ios::failbit);
    string kto{"argument pierwszy"};
    double x;
    bool dane_z_pliku{false};
    bool dane_z_porty{false};
    int nr_portu;
    string nazwa_pliku;
    string co;

    try
    {
        kto = "argument pierwszy";
        sp >> x;
        cout << "Liczba bedaca pierwszym argumenetem " << x << endl;

        kto = "argument drugi";
        sp >> co;

        kto = "argument trzeci";
        if (co == "-port")
        {
            dane_z_porty = true;
            sp >> nr_portu;
        }
        else if (co == "-file")
        {
            dane_z_pliku = true;
            sp >> nazwa_pliku;
        }
        else
        {
            cout << "Nierozpoznany parametr [wybor] " << argv[2] << endl;
            info();
            return 6;
        }
    }
    catch (ios::failure const &kapsula)
    {
        cout << "Blad fail w casie dekodowania przyjmowania argumentow\n"
                "spowodowal " + kto << endl;
        info();
        return 7;
    }
    cout << "Przyjete parametry pracy\n\tOgolny czynnik x = " << x << endl;
    if (dane_z_pliku)
        cout << "\tDane do analizy pliku: " << nazwa_pliku << endl;
    if (dane_z_porty)
        cout << "\tDane do analizy z portu: " << nr_portu << endl;
}