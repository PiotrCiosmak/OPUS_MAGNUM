#include <iostream>
#include <string>
#include <vector>

using namespace std;

//**********************************************************
class Tznajacy_magie
{
    int wtajemniczenie;
    int krag;
public:
    Tznajacy_magie(int wtajemniczenie_arg, int kr) :
            wtajemniczenie(wtajemniczenie_arg), krag(kr)
    {}

    void zaklinaj(int)
    {
        cout << "zaklinam, bo znam " << wtajemniczenie << " wtajemniczen"
             << ", krag nr " << krag << endl;
        return;
    }

    virtual string jego_imie()
    { return ""; }
};

//************************************************************
class Twalczacy_mieczem
{
    int dlugosc;   // w centymetrach
public:
    Twalczacy_mieczem(int dlugosc_miecza) : dlugosc(dlugosc_miecza)
    {}

    void walcz()
    {
        cout << "walcze mieczem o dlugosci " << dlugosc << " centymetrow\n";
    }

    virtual string jego_imie()
    { return ""; }
};

//************************************************************
class Tlatajacy_na_smoku
{
    int skrzydel;
public:
    Tlatajacy_na_smoku(int ile_skrzydel_ma_smok)
            : skrzydel(ile_skrzydel_ma_smok)
    {}

    void lec()
    {
        cout << " Lece na smoku, ktory ma skrzydel: " << skrzydel << endl;
        return;
    }

    virtual string jego_imie()
    { return ""; }
};

////////////////////////////////////////////////////////////////////////////////////
template<typename ... Tklas_podst_sprawnosci>
class Tpostac_gry : public Tklas_podst_sprawnosci ...
{
    string imie;
public:
    Tpostac_gry(string naz, Tklas_podst_sprawnosci...  klps) :
            Tklas_podst_sprawnosci(klps)...,
    imie(naz)
    {
    }

    string jego_imie()
    { return imie; }        // virtualna
};

//***************************************************************
void zaklete_zamczysko(Tznajacy_magie* p)
{
    cout << "Magik "
         << p->jego_imie()
         << " dziala w zakletym zamczysku: " << endl;
    p->zaklinaj(1);
}

//***************************************************************
void pokonaj_przepasc(Tlatajacy_na_smoku* p)
{
    cout << p->jego_imie() << " leci na smoku:  ";
    p->lec();
}

//***************************************************************
void bitwa_rycerska(Twalczacy_mieczem* p)
{
    cout << p->jego_imie() << " walczy: ";
    p->walcz();
}

//*********************************************************
int main()
{
    cout << "Powolanie postaci";

    Tpostac_gry<Tznajacy_magie> merlin{"Merlin czarodziej", {10, 2}};
    Tpostac_gry<Tlatajacy_na_smoku> severus{"Severus", {4}};
    Tpostac_gry<Twalczacy_mieczem> mietek{"Mietek", {120}};
    Tpostac_gry<Tlatajacy_na_smoku, Twalczacy_mieczem> dratewka{
            "Dratewka", {6}, {130}};

    Tpostac_gry<Twalczacy_mieczem, Tlatajacy_na_smoku, Tznajacy_magie>
            tristan{"Tristan", {140}, {2}, {2, 5}};

    Tpostac_gry<Tznajacy_magie, Twalczacy_mieczem>
            rodryk{"Rodryk", {6, 3}, {150}};

    cout << "Poczatek opowiesci ";

    // do zadań magicznych można posłać następujące  postacie
    zaklete_zamczysko(&merlin);
    zaklete_zamczysko(&tristan);
    zaklete_zamczysko(&rodryk);

    // do lotów na smokach można posłać następujące  postacie
    pokonaj_przepasc(&severus);
    pokonaj_przepasc(&dratewka);
    pokonaj_przepasc(&tristan);

    // do bitwy można posłać następujące postacie
    bitwa_rycerska(&mietek);
    bitwa_rycerska(&dratewka);
    bitwa_rycerska(&tristan);
    bitwa_rycerska(&rodryk);
}