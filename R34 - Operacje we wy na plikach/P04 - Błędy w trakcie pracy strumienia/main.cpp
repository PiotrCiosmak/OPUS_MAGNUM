#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Tslowo_na_e
{
public:
    string wyraz;
};

istream &operator>>(istream &str, Tslowo_na_e &w)
{
    str >> w.wyraz;
    if (w.wyraz[0] != 'e')
        str.setstate(ios::failbit);
    return str;
}

int main()
{
    Tslowo_na_e pierwsze, drugie, trzecie;
    while (1)
    {
        cout << "Podaj 3 slowa na litere 'e':";
        cin >> pierwsze >> drugie >> trzecie;
        if (!cin)
        {
            cout <<boolalpha "\nZle! Od poczatku.";
            cin.clear(cin.rdstate() & ~ios::failbit);
        }
        else
            break;
    }
}