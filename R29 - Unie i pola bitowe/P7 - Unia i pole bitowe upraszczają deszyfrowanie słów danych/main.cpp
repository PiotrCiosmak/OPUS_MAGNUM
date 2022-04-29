#include <iostream>
#include <cstring>

using namespace std;

constexpr int MAX_URZADZ{15};
constexpr int MAX_CZUJN{10};

//tablica na wyniki pomiarów
int detektor[MAX_URZADZ][MAX_CZUJN];

//deklaracje funkcji
bool odczytaj_zdarzenie();

void analizuj_zdarzenie();

uint32_t pobierz_slowo_danych();

int main()
{
    cout << "Pogram analizujacy ciagle dostarczane dane pomiarowe" << endl;
    while (odczytaj_zdarzenie())
        analizuj_zdarzenie();
    cout << "Nie ma wiecej danych, konczymy" << endl;
}

bool odczytaj_zdarzenie()
{
    //Lokalna struktura składająca się z pól bitowych reprezentujących grupy bitów słowa przychodzącego z ukladu VXI
    struct Tslowo_vxi
    {
        unsigned int dana: 16;
        unsigned int urzadzenie: 8;
        unsigned int czujnik: 6;
        unsigned int : 2;
    };

    //anonimowa unia, dzięki któej słowo możemy zobaczyć w postaci pociętej na pola
    union
    {
        uint32_t cale_slowo;
        Tslowo_vxi pole;
    };

    cout << "Nastepne zdarzenie..." << endl;

    while (true)
    {
        cale_slowo = pobierz_slowo_danych();
        if (cale_slowo == 0)
            return false;

        if (pole.urzadzenie == 0xf8)
        {
            //numer urzadzenia 0xf8 oznacza, że to tzw. znacznik końca zdarzenia
            cout << "Zakonczony odczyt slow zdarzenia nr" << pole.dana << endl;
            return true;
        }
        else
        {
            if ((pole.urzadzenie < MAX_URZADZ) || (pole.czujnik < MAX_CZUJN))
                detektor[pole.urzadzenie][pole.czujnik] = pole.dana;
        }
    }
}

void analizuj_zdarzenie()
{
    cout << "Analiza zdarzenia. W tym zdarzeniu zadzialaly:" << endl;
    for (int u = 0; u < MAX_URZADZ; ++u)
        for (int c = 0; c < MAX_CZUJN; ++c)
            if (detektor[u][c])
                cout << "\turzadzenie " << u << ", czujnik " << c << ", odczyt = " << detektor[u][c] << endl;
}

uint32_t pobierz_slowo_danych()
{
    static uint32_t dane[] =
            {
                    0x4060658, 0x60201ff, 0x9058c, 0xf80000, 328457, 100729404, 0xf80001,
                    197827, 134417127, 84087033, 50927293, 16848207, 17105686,
                    16847128, 0xf80002,
                    0
            };
    static int licznik;
    return dane[licznik++];
}