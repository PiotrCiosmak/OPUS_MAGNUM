#include <iostream>

using namespace std;

class Tstrunowy
{
public:
    int liczba_lat;

    Tstrunowy() : liczba_lat{0}
    {}

    virtual Tstrunowy *stworz_nowy_dziewiczy() = 0;

    virtual Tstrunowy *stworz_nowy_sklonowany() = 0;

    virtual void jestem() = 0;
};

class Tskrzypce : public Tstrunowy
{
public:
    void jestem()
    {
        cout << "Jestem klasy Tskrzypce, mam lat = " << liczba_lat << "\n";
    }

private:
    Tstrunowy *stworz_nowy_dziewiczy()
    {
        return new Tskrzypce;
    }

    Tstrunowy *stworz_nowy_sklonowany()
    {
        return new Tskrzypce(*this);
    }
};

class Twiolonczela : public Tstrunowy
{
public:
    void jestem()
    {
        cout << "Jestem klasy Twiolonczela, mam lat = " << liczba_lat << "\n";
    }

private:
    Tstrunowy *stworz_nowy_dziewiczy()
    {
        return new Twiolonczela;
    }

    Tstrunowy *stworz_nowy_sklonowany()
    {
        return new Twiolonczela(*this);
    }
};

int main()
{
    Tskrzypce skrz;
    Twiolonczela wiol;

    wiol.liczba_lat = 157;
    skrz.jestem();
    wiol.jestem();
    cout << "Teraz bedziemy wirtualnie konstrukowac dodatkowe obiekty\n";
    Tstrunowy *wskaznik = &skrz;
    Tstrunowy *wsk1 = wskaznik->stworz_nowy_dziewiczy();
    wsk1->jestem();

    wskaznik = &wiol;

    Tstrunowy *wsk2 = wskaznik->stworz_nowy_dziewiczy();
    wsk2->jestem();

    Tstrunowy *wsk3 = wskaznik->stworz_nowy_sklonowany();
    wsk3->jestem();

    delete wsk1;
    delete wsk2;
    delete wsk3;
}