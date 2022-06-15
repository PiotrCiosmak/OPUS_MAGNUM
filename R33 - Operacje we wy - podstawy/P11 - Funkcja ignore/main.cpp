#include <iostream>

using namespace std;

int main()
{
    char kuferek[10];
    char skrytka[10];
    cout << "Napisz okolo 10 znakow:";
    cin.get(kuferek, 4).ignore(2).get(skrytka, 10);
    cout << "W kuferku jest: " << kuferek << ", w skrytce jest: " << skrytka << "\na dwa znaki zignorowalem" << endl;
}