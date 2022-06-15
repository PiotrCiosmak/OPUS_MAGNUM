#include <iostream>

using namespace std;

int main()
{
    char tablica[200];
    cout << "Napisz jakies zdanie:";
    cin.get(tablica, sizeof(tablica), 'x');

    cout << "Ze strumienia wyjete zostalo: " << (cin.gcount()) << " znakow, oto zdanie: " << tablica << endl;
}