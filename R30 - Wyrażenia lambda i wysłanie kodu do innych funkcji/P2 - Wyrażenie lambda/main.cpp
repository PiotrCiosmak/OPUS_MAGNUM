#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v{4, 2, 13, 11, 5, 24, 7};

    auto pocz = v.begin();
    auto kon = v.end();
    cout << "Uzywajac wyrazen lambda, ustalamy, ze w wektorze v:" << endl;

    int ile = count_if(pocz, kon, [](int liczba) { return (liczba % 2); });
    cout << "\tNieparzystych liczb jest " << ile << endl;

    ile = count_if(pocz, kon, [](int liczba) { return (liczba > 9); });
    cout << "\tLiczb > 9 jest " << ile << endl;

    for (int k = 3; k < 6; ++k)
    {
        ile = count_if(pocz, kon, [k](int liczba) { return (liczba > k); });
        cout << "\t\tLiczb > " << k << " jest " << ile << endl;
    }

    cout << "Ciekawostka, wyrazenie lambda nie musi byc wysylane do funkcji..." << endl;
    [](string txt) { cout << "Lambda: Przeslano mi " << txt << endl; }("argo");
}