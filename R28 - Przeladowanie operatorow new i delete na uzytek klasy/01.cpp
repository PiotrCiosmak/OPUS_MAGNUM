#include <iostream>

using namespace std;

#define TEST_NIEPOWODZENIA rozmiar *= 10000000000;

class Twektorek
{
public:
    double x, y, z;

    Twektorek(double a = 0, double b = 0, double c = 0) : x{a}, y{b}, z{c}
    {
        cout << "\tKonstruktor Twektorek inicjalizuje ten obiekt" << endl;
    }

    virtual ~Twektorek()
    {
        cout << "\tDestruktor kl. Twektorek" << endl;
    }

    void wypisz()
    {
        cout << "\tx=" << x << ", y=" << y << ", z=" << z << endl;
    }

    //rezerwacja miejsca(te funkcje mogą rzucać wyjątek std::bad_alloc)
    void *operator new(size_t rozmiar);

    void *operator new[](size_t rozmiar);

    //z argumentami użytkownika wg. schematu
    //void* operator new(size_t rozmiar, argumenty użytkownika...);
    void *operator new(size_t rozmiar, bool stan);

    void *operator new(size_t rozmiar, double r, int n);

    //Uwaga: z operatora delete nie powinno się rzucać wyjątków
    //void operator delete(void *wsk) noexcept;
    void operator delete(void *wsk,
                         size_t rozmiar) noexcept; //lepsza wersja (działa przy klasach dziedziczących ten operator)

    //void operator delete [](void*wsk) noexcept;
    void operator delete[](void *wsk,
                           size_t rozmiar) noexcept; //lepsza wersja (działa przy klasach dziedziczących ten operator)

    //Dotychczasowe funkcje operatorowe new w razie niepowodzenia mogły rzucać wyjątek
    //Poniżej są takie wersje, które używamy, gdy zamiast wyjątku wolim zwrot adresu nullptr
    void *operator new(size_t rozmiar, const nothrow_t &) noexcept;

    void *operator new(size_t rozmiar, const nothrow_t &, bool stan) noexcept;

    void *operator new(size_t rozmiar, const nothrow_t &, double r, int n) noexcept;

    void *operator new[](size_t rozmiar, const nothrow_t &) noexcept;
};

void *Twektorek::operator new(size_t rozmiar)
{
    cout << "Rezer. pamieci na pojedynczy obiekt, new(size_t), gdzie rozmiar =" << rozmiar << endl;
    //nasze dodatkowe akcje
    return (::new char[rozmiar]);
}

void Twektorek::operator delete(void *wsk, size_t rozmiar) noexcept
{
    if (wsk != nullptr)
    {
        cout << "Odwolanie rezerw. delete (void *wsk) noexcept" << endl;
        ::delete[] static_cast<char *> (wsk);
    }
}

int main()
{
    try
    {
        Twektorek *w1;
        w1 = new Twektorek{1, 1, 1};
        w1->wypisz();
        delete w1;
    }
    catch (bad_alloc &e)
    {
        cout << "Zlapany obiekt wyjatku klast std::alloc" << endl;
    }
}