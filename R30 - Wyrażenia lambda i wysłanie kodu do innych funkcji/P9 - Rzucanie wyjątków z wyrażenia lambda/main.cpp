#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>

using namespace std;

class Twyjatek
{
public:
    Twyjatek(string txt, int wart) : wiadomosc{txt}, liczba{wart}
    {}

public:
    string wiadomosc;
    int liczba;
};

int main()
{
    vector<int> v{49, 87, 16, 89, -27, 324};
    vector<double> pierwiastki;
    pierwiastki.resize(v.size());

    cout << "Wartosci, ktore kolejno pierwiastkujemy" << endl;
    try
    {
        std::transform(v.begin(), v.end(), pierwiastki.begin(), [](int dana)
        {
            cout << dana << ", " << flush;
            if (dana < 0)
                throw Twyjatek{"Niedozwolona wartosc ujemna", dana};
            return sqrt(dana);
        });

        cout << "\nSukces, wypelniony wektor rezultatow:" << endl;
        for (auto d: pierwiastki)
            cout << d << ", " << flush;
    }
    catch (Twyjatek ex)
    {
        cout << "!!!\nObliczenia przerwane bo:\n\t"
             << ex.wiadomosc << " " << ex.liczba << endl;
    }

    cout << "\nDalszy ewentualny ciag programu..." << endl;
}