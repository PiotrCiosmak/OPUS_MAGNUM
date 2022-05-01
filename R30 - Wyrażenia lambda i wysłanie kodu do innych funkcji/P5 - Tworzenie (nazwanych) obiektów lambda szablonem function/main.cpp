#include <iostream>
#include <vector>
#include <algorithm> //dla funkcji for_each
#include <functional> //dla std::function

using namespace std;

void moj_algorytm(vector<double> poj, std::function<void(double)> czynnosc);

void zwykla(double a);

int main()
{
    auto wypisz = [](double s) { cout << "Lambda 'wypisz':s = " << s << endl; };

    std::function<void(double)> do_kwadratu = [](double x) { cout << "'kwadrat': " << x << " --> " << x * x << endl; };

    cout << "Wyslanie tego wyrazenia lambda do algorytmu for_each" << endl;
    vector<double> v{4.5, 13, 25};
    for_each(v.begin(), v.end(), do_kwadratu);

    cout << "Teraz wyslemy wyrazenie lambda do naszej funkcji" << endl;
    moj_algorytm(v, wypisz);
    moj_algorytm(v, [](double y) { cout << "och, " << y << endl; });
    moj_algorytm(v, do_kwadratu);

    cout << "\nCzy moj_algorytm potrafi przyjac rowniez adres zwyklej funkcji?" << endl;
    moj_algorytm(v, zwykla);

    moj_algorytm(v, nullptr);
    moj_algorytm(v, 0);
}

void moj_algorytm(vector<double> poj, std::function<void(double)> czynnosc)
{
    if (czynnosc == nullptr)
    {
        cout << "Niepoprawny adres dostarczony 'czynnosci'" << endl;
        return;
    }
    for (double elem: poj)
    {
        cout << "moj_algorytm wywoluje czynnosc(" << elem << ") -->\t";
        czynnosc(elem);
    }
}

void zwykla(double a)
{
    cout << "zwykla funkcja, a = " << a + 1000 << endl;
}