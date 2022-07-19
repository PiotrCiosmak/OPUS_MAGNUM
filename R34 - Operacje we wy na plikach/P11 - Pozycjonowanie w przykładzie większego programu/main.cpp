#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

class Tduza_tablica
{
public:
    Tduza_tablica(string nazwa, int wym, int wypelniacz = 0);

    ~Tduza_tablica();

    int *operator[](int wiersz);

private:
    string nazwa_pliku;
    fstream plik;
    const int rozmiar;
    int *linijka;
    long dlug_linijki;
    int nr_obecnego;

    void error();
};

Tduza_tablica::Tduza_tablica(string nazwa, int wym, int wypelniacz) : nazwa_pliku(nazwa), rozmiar(wym)
{
    plik.open(nazwa, ios::trunc | ios::in | ios::out | ios::binary);
    if (!plik)
    {
        cout << "Blad otwarcia pliku " << nazwa_pliku << endl;
        error();
    }
    linijka = new int[rozmiar];
    dlug_linijki = rozmiar * sizeof(int);

    //wstepne wypełnienie
    for (int i = 0; i < rozmiar; ++i)
        linijka[i] = wypelniacz;

    //zapis tego do pliku
    for (int i = 0; i < rozmiar && plik.good(); ++i)
        plik.write((char *) linijka, dlug_linijki);
    if (!plik)
    {
        cout << "Blad podczas wypelnienia tablicy" << endl;
        error();
    }
    nr_obecnego = 0;
}

Tduza_tablica::~Tduza_tablica()
{
    //skoro koniec, to musimy odesłać na dysk wiersz, który jest jeszcze w tablicy
    if (plik.seekp(nr_obecnego * dlug_linijki))
    {
        cout << "Blad pozycjonowania wskaznika pisania\n";
        error();
    }

    //zapisanie tamżę...
    if (!plik.write((char *) linijka, dlug_linijki))
    {
        cout << "Blad przy odsylaniu\n";
        error();
    }
    plik.close();
    delete[]linijka;
}

int *Tduza_tablica::operator[](int nr_wiersza_chcianego)
{
    //moze dany fragment tablicy jest pod ręką?
    if (nr_wiersza_chcianego == nr_obecnego) return linijka;

    //jeśli nie, to najpierw odsyłamy obecny wiersz
    if (!plik.seekp(nr_obecnego * dlug_linijki))
    {
        cout << "Blad pozycjonowania wskaznika pisania\n";
        error();
    }
    //zapisanie tam
    if (!plik.write((char *) linijka, dlug_linijki));
    {
        cout << "Blad przy odsylaniu\n";
        error();
    }

    //sprowadzamy nowy wiersz
    //obliczanie, gdzie jest w pliku
    if (!plik.seekg(nr_wiersza_chcianego * dlug_linijki))
    {
        cout << "Blad pozycjonowania wskaznika czytania " << nr_wiersza_chcianego * dlug_linijki << endl;
        error();
    }

    //przeczytanie fragmentu
    if (!plik.read((char *) linijka, dlug_linijki))
    {
        cout << "Blad czytania wiersza " << nr_wiersza_chcianego << endl;
        error();
    }

    nr_obecnego = nr_wiersza_chcianego;
    return linijka;
}

void Tduza_tablica::error()
{
    if (plik.eof())
        cout << "Koniec pliku";
    if (plik.fail())
        cout << "-FAIL strumienia do pliku: " << nazwa_pliku << endl;
    exit(1);
}

int main()
{
    int i, j;
    const int wymiary{50};
    Tduza_tablica t("macierz.tmp", wymiary);

    //wpisanie jakichś danych do tablicy t
    for (i = 0; i < wymiary; ++i)
        for (j = 0; j < wymiary; ++j)
            t[i][j] = i * 100 + j;

    cout << "Przykladowo zrobimy transpozycje\n";
    Tduza_tablica m("macierz1.tmp", wymiary);
    for (i = 0; i < wymiary; ++i)
        for (j = 0; j < wymiary; ++j)
            m[i][j] = t[i][j];

    cout << "transpozycja skonczona, oto rezultat\n"
            "Przykladowo element t[7][31] = " << t[7][31]
         << ", \tt[31][7] = " << t[31][7] << endl;
    cout << "Natomiast element m[7][31] = " << m[7][31]
         << ", \tm[31][7] = " << m[31][7] << endl;
}