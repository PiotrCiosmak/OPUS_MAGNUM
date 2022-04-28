#ifndef OPUS_MAGNUM_TWEKTOREK_HPP
#define OPUS_MAGNUM_TWEKTOREK_HPP

#include <iostream>

#define TEST_NIEPOWODZENIA rozmiar *= 10000000000;

class Twektorek
{
public:
    double x, y, z;

    Twektorek(double a = 0, double b = 0, double c = 0) : x{a}, y{b}, z{c}
    {
        std::cout << "\tKonstruktor Twektorek inicjalizuje ten obiekt" << std::endl;
    }

    virtual ~Twektorek()
    {
        std::cout << "\tDestruktor kl. Twektorek" << std::endl;
    }

    void wypisz()
    {
        std::cout << "\tx=" << x << ", y=" << y << ", z=" << z << std::endl;
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
    void *operator new(size_t rozmiar, const std::nothrow_t &) noexcept;

    void *operator new(size_t rozmiar, const std::nothrow_t &, bool stan) noexcept;

    void *operator new(size_t rozmiar, const std::nothrow_t &, double r, int n) noexcept;

    void *operator new[](size_t rozmiar, const std::nothrow_t &) noexcept;
};

#endif //OPUS_MAGNUM_TWEKTOREK_HPP