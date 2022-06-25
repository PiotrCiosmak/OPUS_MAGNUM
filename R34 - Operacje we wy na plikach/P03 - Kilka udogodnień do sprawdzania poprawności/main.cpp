#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    //Tak to wygląda w praktyce
    int liczba;
    cin >> liczba;
    if (cin)
        cout << "Sukces" << endl;
    if (!cin)
        cout << "Niepowodzenie" << endl;

    //To samo bez tych pomocnych funkcji wymaga więcej pisania
    if (!cin.fail())
        cout << "Sukces" << endl;
    if (cin.fail())
        cout << "Niepowodzenie" << endl;

    //Poprawność przeprowadzanych operacji można sprawdzać nawet w taki sposób:
    if (cin >> liczba)cout << "sukces!";
}