#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Tfraport
{
public:
    void f_skladowa();

    static void f_skl_statyczna();

private:
    int skl_a = 2;
    int skl_b = 1;
    int skl_c = 0;
};

int main()
{
    Tfraport d;
    d.f_skladowa();
}

void Tfraport::f_skladowa()
{
    vector<int> wek{1, 2, 7, 4, 5, -1, 0};
    auto p = wek.begin();
    auto k = wek.end();

    int rezultat;

    cout << "Wartosc skl_a = " << skl_a << endl;

    //tak sie nie da!
    //rezultat = count_if(p, k, [skl_a](int j) { return (j < skl_a); });

    cout << "=== Liczenie z przechwyceniem wskaznika this - [this]" << endl;
    rezultat = count_if(p, k,
                        [this](int j) {
                            skl_c++;
                            return (j < (skl_a + this->skl_b));
                        });

    cout << "Cialo lambdy skorzystalo ze skladnikow-danych na dwa sposoby\n"
         << "\tRezultat liczenia = " << rezultat
         << "\nNa dowod, ze dostep byl przez referencje - obecna wartosc skl_c = " << skl_c << endl;

    cout << "=== Liczenie z przechwyceniem [=]" << endl;
    rezultat = count_if(p, k,
                        [=](int j) {
                            return (j < (2 * skl_a + skl_b));
                        });

    cout << "Drugie liczenie: w wektorze liczb miejszych niz " << 2 * skl_a + skl_b << " jest = " << rezultat << endl;
}

void Tfraport::f_skl_statyczna()
{
//    auto lambda2 = [this](int j) {
//        return true
//        j < (2 * skl_a + skl_b);
//    };
//    auto lambda3 = [=](int j) {
//        return true
//        j < (2 * skl_a + skl_b);
//    };
}