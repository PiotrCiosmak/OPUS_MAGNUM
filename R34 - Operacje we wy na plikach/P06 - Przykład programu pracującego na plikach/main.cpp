#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string plikA,
            plikB;

    cout << "Podaj nazwe pliku wejsciowego:";
    cin >> plikA;
    ifstream czyt{plikA};
    if (!czyt)
    {
        cout << "Nie moge otworzyc takiego pliku";
        return 1;
    }

    cout << "Podaj nazwe pliku wyjsciowego:";
    cin >> plikB;
    ofstream pisz{plikB};
    if (!pisz)
    {
        cout << "Nie moge otworzyc takiego pliku";
        return 1;
    }

    char c;
    while (czyt.get(c))
    {
        if (!pisz.put(c))
        {
            cout << "Blad pisania!\n";
            break;
        }
    }

    if (!czyt.eof())
    {
        cout << "Blad czytania!\n";
    }
}