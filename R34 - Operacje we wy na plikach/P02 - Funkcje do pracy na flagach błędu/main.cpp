#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    //1. bool good();
    char znak;
    do
    {
        cin >> znak;
        cout << znak;
    } while (cin.good() && znak != 'q');

    //2. bool eof();
    char dane[1000];
    ifstream s("wtorek.tmp", ios::in | ios::binary);
    //pomijamy sprawdzenie poprawności otwarcia pliku
    s.read(dane, sizeof(dane));
    if (s.eof())
        cout << "Napotkany EOF przed wczytanie 1000 bajtow" << endl;
    else
        cout << "Poprawnie wczytane 1000 bajtow" << endl;

    //3. bool fail();
    int liczba;
    cin >> liczba;
    if (cin.fail())
        cout << "Zle podana liczba!" << endl;

    //4. bool bad()
    //Funkcja to zwraca wartośc true, gdy flaga badbit jest ustawiona. Tak zdarzy się wtedy, gdy strumień zostanie poważnie uszkodzony (zepsuty)
}