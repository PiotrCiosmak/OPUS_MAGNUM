#include <iostream>

using namespace std;

int main()
{
    char kuferek[10]{"xxxxxxxxx"};
    cout << "Napis max 9 znakow:";
    cin.getline(kuferek, sizeof(kuferek), 's');

    cout << "Oto zawartosc elementow kuferka:\n";
    for (int i = 0; i < sizeof(kuferek); ++i)
    {
        cout << "kuferek[" << i << "]=" << kuferek[i] << endl;
    }
    cout<<"Nastepnie wyjety znak: "<<static_cast<char>(cin.get());
}