#ifndef OPUS_MAGNUM_TPOJAZD_HPP
#define OPUS_MAGNUM_TPOJAZD_HPP

class Tpojazd
{
public:
    Tpojazd(int ile) : liczba_kol{ile}, tabl_gps{new double[ile_wspolrzednych]}
    {}

    //Mechanizmy kopiowania obiektów tej klasy realizują:
    Tpojazd(const Tpojazd &wzor); //konstruktor kopiujący
    Tpojazd &operator=(const Tpojazd &wz); //kopiujący operator przypisania

    //Mechanizmy przenoszenia realzują:
    Tpojazd(Tpojazd && zlom); //konstruktor przenoszący
    Tpojazd &operator=(Tpojazd &&odzysk);// przenoszący operator przypisania

    //dla upewnienia się, czy poprawnie skopiowano tablicę współrzędnych
    void zmien_pozycje(double x, double y)
    {
        tabl_gps[0] = x;
        tabl_gps[1] = y;
    }

protected:
    int liczba_kol;
    double *tabl_gps;
    static constexpr int ile_wspolrzednych{2};
};

#endif //OPUS_MAGNUM_TPOJAZD_HPP