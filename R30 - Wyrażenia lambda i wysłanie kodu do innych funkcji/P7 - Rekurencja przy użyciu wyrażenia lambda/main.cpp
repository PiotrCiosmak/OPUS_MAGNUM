#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

std::function<void(int)> wypisz_dwojkowy;

int main()
{
    if (wypisz_dwojkowy == nullptr)
        cout << "To dowod, ze na razie obiekt lambda jest pusty..." << endl;
    wypisz_dwojkowy = [](int liczba)
    {
        int reszta = liczba % 2;
        if (liczba > 1)
            wypisz_dwojkowy(liczba / 2);
        else
            cout << " ";
        cout << reszta;
        return;
    };
    cout << "Na przyklad 5 to dwojkowo = ";
    wypisz_dwojkowy(5);

    cout << "\nWyslanie tego wyrazenia lambda do algorytmu for_each" << endl;
    vector<int> zbior{0, 1, 2, 3, 10, 11, 12, 13, 14};
    for_each(zbior.begin(), zbior.end(), wypisz_dwojkowy);

    //inny sposób - zlokalną definicją obektu lambda
    std::function<void(int)> wr;
    wr = [&wr](int liczba)
    {
        int reszta = liczba % 2;
        if (liczba > 1)
            wypisz_dwojkowy(liczba / 2);
        else
            cout << " ";
        cout << reszta;
        return;
    };

    cout << "\nLokalnie deklrowane wyrazenie lambda --------\n"
            "Na przyklad 7 to dwojkowo = ";
    wr(7);

    cout << "\nWwyslanie wyrazenia lambda 'wr' do algorytmu for_each" << endl;
    for_each(zbior.begin(), zbior.end(), wr);
}