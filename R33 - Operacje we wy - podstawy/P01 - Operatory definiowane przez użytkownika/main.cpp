#include <iostream>

using namespace std;

class Twekt
{
    friend ostream &operator<<(ostream &strumien_wyj, const Twekt &w);

    friend istream &operator>>(istream &strumien_wej, Twekt &w);

private:
    double x, y, z;
};

/*ostream &operator<<(ostream &strumien_wyj, const Twekt &w)
{
    strumien_wyj << w.x << " " << w.y << " " << w.z;
    return strumien_wyj;
}

istream &operator>>(istream &strumien_wej, Twekt &w)
{
    strumien_wej >> w.x >> w.y >> w.z;
    return strumien_wej;
}*/

ostream &operator<<(ostream &strumien_wyj, const Twekt &w)
{
    strumien_wyj << w.x << ", " << w.y << ", " << w.z;
    return strumien_wyj;
}

istream &operator>>(istream &strumien_wej, Twekt &w)
{
    char znak;
    strumien_wej >> w.x >> znak >> w.y >> znak >> w.z;
    return strumien_wej;
}

class Twektor_z_opisem : public Twekt
{
    friend ostream &operator<<(ostream &strumien_wyj, Twektor_z_opisem &w);

    friend istream &operator>>(istream &strumien_wej, Twektor_z_opisem &w);

private:
    char opis[30];
};

ostream &operator<<(ostream &strumien_wyj, Twektor_z_opisem &w)
{
    strumien_wyj << static_cast<Twekt &>(w);
    strumien_wyj << " " << w.opis;
    return strumien_wyj;
}

istream &operator>>(istream &strumien_wej, Twektor_z_opisem &w)
{
    strumien_wej >> static_cast<Twekt &>(w);
    strumien_wej >> w.opis;
    return strumien_wej;
}

int main()
{
    Twekt a, b;
    cout << "Podaj wspolrzedne wektora a";
    cin >> a;

    cout << "Podaj wspolrzedne wektora b";
    cin >> b;

    cout << "Wektor a ma wspolrzedne [" << a << "]\n";
    cout << "Wektor b ma wspolrzedne [" << b << "]\n";

}