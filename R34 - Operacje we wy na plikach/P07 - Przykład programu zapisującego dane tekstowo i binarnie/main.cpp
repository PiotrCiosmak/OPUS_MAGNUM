#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

class Twekt
{
public:
    double x, y, z;
};

ostream &operator<<(ostream &strumien_wyj, const Twekt &w)
{
    strumien_wyj << w.x << " " << w.y << " " << w.z;
    return strumien_wyj;
}

istream &operator>>(istream &strumien_wej, Twekt &w)
{
    strumien_wej >> w.x >> w.y >> w.z;
}

void error(string opis)
{
    cout << "Opis bledu: " << opis << "\nKonczymy program" << endl;
    exit(2);
}

int main()
{
    double d{1234.567890123};
    int n{255};
    string txt{"to jest wyelowyrazowy tekst"};
    string komunikat{"to jest \nkilka linijek\nciekawego tekstu"};
    Twekt wek{20, 30, 40};
    //------------------------------------------------------------
    cout << "----------Zapis danych do pliku tekstowego\n";
    string nazwa_pliku_tekstowego{"plik.txt"};
    ofstream strumA(nazwa_pliku_tekstowego);//tryb nie jest binarny, więc jest tekstowy
    if (!strumA)
        error("Nie moge otworzyc pliku: " + nazwa_pliku_tekstowego + " do zapisu");

    strumA << setprecision(15) << d;
    strumA << " " << n;
    strumA << '\n' << txt << endl;
    strumA << komunikat;
    strumA << '$' << endl;
    strumA << wek;

    if (!strumA)
        error("Nie powiodla sie jedna z operacji zapisu tekstowego");
    strumA.close();

    //------------------------------------------------------------
    cout << "----------Odczytanie danych z pliku tekstowego\n";
    double d2;
    int n2;
    string txt2;
    string kom2;
    Twekt wek2;

    ifstream strum2(nazwa_pliku_tekstowego); //otwieramy tekstowo
    if (!strum2)
        error("Nie moge otworzyc pliku: " + nazwa_pliku_tekstowego + " do odczytu");

    //wczytujemy w tej samej kolejności, w której pisaliśmy
    strum2 >> d2 >> n2;
    strum2 >> ws; //podjedź do początku tekstu
    getline(strum2, txt2);
    getline(strum2, kom2, '$');
    strum2 >> wek2;

    if (!strum2)
        error("Nie powiodla sie jedna z operacji odczytu tekstowego");
    strum2.close();

    cout << "Odczytane z dysku wartosci:\n"
         << setprecision(15) << d2 << '\n' << n2 << '\n' << txt2 << '\n' << kom2
         << "\nwektor o skladnikach:"
         << wek2.x << " " << wek2.y << " " << wek2.z << endl;

    //sprawdzenie, czy nie bylo przekłamań
    if (d != d2) error("zle wczytane d2");
    if (n != n2) error("zle wczytane n2");
    if (txt != txt2) error("zle wczytane txt2");
    if (komunikat != kom2) error("zle wczytane kom2");
    if (wek.x != wek2.x || wek.y != wek2.y || wek.z != wek2.z) error("zle wczytane wek2");

    //------------------------------------------------------------
    cout << "----------Zapis danych do pliku binarnego\n";
    string nazwa_pliku_binarnego{"plik.bin"};
    ofstream plikB("plik.bin", ios::out | ios::binary);
    if (!plikB)
        error("Nie moge otworzyc pliku: " + nazwa_pliku_binarnego + " do zapisu");

    plikB.write((char *) &d, sizeof(d));
    plikB.write((char *) &n, sizeof(n));

    int dlugosc_txt = txt.size();
    plikB.write((char *) &dlugosc_txt, sizeof(dlugosc_txt));
    plikB.write((char *) txt.data(), sizeof(char) * dlugosc_txt);

    int dlugosc_kom = komunikat.size();
    plikB.write((char *) &dlugosc_kom, sizeof(dlugosc_kom));
    plikB.write((char *) komunikat.data(), sizeof(char) * dlugosc_kom);

    plikB.write((char *) &wek, sizeof(wek));

    if (!plikB)
        error("Blad w pisaniu do pliku: " + nazwa_pliku_binarnego);
    plikB.close();

    //------------------------------------------------------------
    cout << "----------Odczyt danych z pliku binarnego\n";
    ifstream s("plik.bin", ios::in | ios::binary);
    if (!s)
        error("Nie moge otworzyc pliku: " + nazwa_pliku_binarnego + " do odczytu");

    double d3;
    int n3;
    string txt3;
    string kom3{};

    s.read((char *) &d3, sizeof(d3));
    s.read((char *) &n3, sizeof(n3));

    int dlugosc;
    s.read((char *) &dlugosc, sizeof(dlugosc)); //wczytanie "ile nastąpi znaków"

    for (int nr = 0; nr < dlugosc; ++nr)
    {
        txt3 += s.get();
        if (!s)
            error("blad czytania txt3 przy znaku nr: " + to_string(nr));
    }

    //Drugi tekst (komunikat) czytamy tak, żeby było jakoś inaczej
    s.read((char *) &dlugosc, sizeof(dlugosc)); //wczytanie liczby znaków następnego tekstu

    char *tablica = new char[dlugosc + 1]{}; // to +1 jest na znak null
    s.read(tablica, dlugosc);
    kom3 = tablica;
    delete[] tablica;
    if (!s)
        error("blad czytania kom3");

    Twekt wek3;
    s.read((char *) &wek3, sizeof(wek3)); //wczytanie całego obiektu wek3
    s.close();

    cout << d3 << '\n' << n3 << '\n' << txt3 << '\n' << kom3
         << "\nwektor ma skladniki:"
         << wek3.x << " " << wek3.y << " " << wek3.z << endl;

    //sprawdzenie czy nie bylo przeklamań
    if (d != d3) error("zle wczytane d3");
    if (n != n3) error("zle wczytane n3");
    if (txt != txt3) error("zle wczytany txt3");
    if (komunikat != kom3) error("zle wczytany kom3");
    if (wek.x != wek3.x || wek.y != wek3.y || wek.z != wek3.z) error("zle wczytane wek3");
    cout<<"Wykonane poprawnie\n";
}