#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream strum;
    string nazwa_pliku;
    /*
     * Niepowodzenie w otwieraniu pliku do czytania można ustawić flagę błędu ios::failbit
     * w razie, gdy plik nie istnieje. Strumień tkwi wówczas w stanie błędu.
     * Aby ponowić próbę otwarcia pliku, flagę tę trzeba najpierw skasować.
    */
    bool sukces{false};

    while (!sukces)
    {
        cout << "Podaj nazwe pliku:";
        cin >> nazwa_pliku;
        cout << endl;

        strum.open(nazwa_pliku, ios::in);
        if (!strum)
        {
            cout << "Blad otwarcia pliku: " << nazwa_pliku << endl;
            //Skoro próba się nie udała to strumień jest w stanie błędu! Musimy usunąć stan błędu strumienia
            strum.clear(strum.rdstate() & ~ios::failbit);
            //strumien jest już w porządku. W koeljnym obiegu pętli ...
            cout << "Ponawiamy probe...\n";
        }
        else
        {
            sukces = true;
            cout << "Plik poprawnie zostal otworzony do czytania\n" << string(50, '#') << endl;
        }
    }//koniec pętli while

    /*
     * Operacje czytania mogą wywołać ustawienie flagi błędu ios::eofbit w przypadku, gdy dojdziemy do końca pliku i mimo to próbujemy czytać nadal.
     * Aby dalej pracować z tym strumieniem, musimy skasować tę flagę błędu (a potem ew. ustawić kursos czytania we wskazane miejsce)
    */
    int numer;
    char znak;
    do
    {
        cout << "Podaj numer bajtu, ktory chcesz poznac:";
        cin >> numer;

        strum.seekg(numer);
        znak = strum.get();
        if (strum.eof())
        {
            sukces = false;
            cout << "Blad pozycjonowania, prawdopodobnie plik\n\rjest krotszy niz " << numer << " bajtow\n";
            //strumień tkwi w stanie błędu ios::eofbit oraz równocześnie ios::failbit, więc trzeba te obie flagi usunąć
            strum.clear(strum.rdstate() & ~(ios::eofbit | ios::failbit));
            cout << "(Podaj mniejsza liczbe)\n";
        }
        else
        {
            sukces = true;
            cout << "Ten bajt to hexadecymalnie: " << showbase << hex << static_cast<int>(znak) << ", a jako znak ASCII: " << znak << "\n" << string(50, '#') << endl;
        }
    } while (!sukces);

    /*
     * Próba formatowanego wczytywania liczby w sytuacji, gdy właśnie oczekuje na wczytanie coś, co liczbą nie jest, wprowadzi strumień w stan błędu ios::failbit
    */
    cout << "Proba wczytania nastepnych znakow jako cyfr liczby..." << endl;
    int liczba;

    strum >> liczba;
    if (strum.fail())
    {
        cout << "Blad failbit, bo najblizsze bajty\n\t nie moga byc wczytane jako liczba\n";
        //Aby to cos wowczas wczytac jako string, nalezy skasowac ustawioną flagę błędu
        strum.clear(strum.rdstate() & ~ios::failbit);
        string slowo;
        strum >> slowo;
        cout << "Jest to slowo: " << slowo << endl;
    }
    else
    {
        cout << "Pomyslanie wczytana liczba: " << liczba << endl;
    }
}