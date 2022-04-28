#include "Twektorek.hpp"

using namespace std;

void *Twektorek::operator new(size_t rozmiar)
{
    cout << "Rezer. pamieci na pojedynczy obiekt, new(size_t), gdzie rozmiar = " << rozmiar << endl;
    //nasze dodatkowe akcje
    //TEST_NIEPOWODZENIA
    return (::new char[rozmiar]);
}

void Twektorek::operator delete(void *wsk, size_t rozmiar) noexcept
{
    if (wsk != nullptr)
    {
        cout << "Odwolanie rezerw. delete (void *wsk, size_t rozmiar) noexcept, rozmiar = " << rozmiar << endl;
        ::delete[] static_cast<char *> (wsk);
    }
}

void *Twektorek::operator new[](size_t rozmiar)
{
    cout << "Rezerw. new[] (size_t rozmiar), rozmiar = " << rozmiar << endl;
    //nasze dodatkowe akcje
    //TEST_NIEPOWODZENIA
    return (::new char[rozmiar]);
}

void Twektorek::operator delete[](void *wsk, size_t rozmiar) noexcept
{
    if (wsk != nullptr)
    {
        cout << "Odwolanie rezerw. delete[](void *wsk, size_t rozmiar), rozmiar = " << rozmiar << endl;
        ::delete[] static_cast<char *>(wsk);
    }
}

void *Twektorek::operator new(size_t rozmiar, bool stan)
{
    cout << "Rezerw. new[] (size_t rozmiar, bool stan), gdzie rozmiar = " << rozmiar
         << ", stan = " << boolalpha << stan << endl;
    //nasze dodatkowe akcje
    //TEST_NIEPOWODZENIA
    return (::new char[rozmiar]);
}

void *Twektorek::operator new(size_t rozmiar, double r, int n)
{
    cout << "Rezerw. new[] (size_t rozmiar, bool stan), gdzie rozmiar = " << rozmiar
         << ", " << r << ", " << n << endl;
    //nasze dodatkowe akcje
    //TEST_NIEPOWODZENIA
    return (::new char[rozmiar]);
}

void *Twektorek::operator new(size_t rozmiar, const nothrow_t &) noexcept
{
    cout << "Rezerw. new(size_t rozmiar, const nothrow_t&) rozmiar = " << rozmiar << endl;
    //nasze dodatkowe akcje
    //TEST_NIEPOWODZENIA
    return (::new(nothrow) char[rozmiar]);
}

void *Twektorek::operator new(size_t rozmiar, const nothrow_t &, bool stan) noexcept
{
    cout << "Rezerw. new[] (size_t rozmiar,const nothrow_t &, bool stan), gdzie rozmiar = " << rozmiar
         << ", stan = " << boolalpha << stan << endl;
    //nasze dodatkowe akcje
    //TEST_NIEPOWODZENIA
    return (::new(nothrow) char[rozmiar]);
}

void *Twektorek::operator new(size_t rozmiar, const nothrow_t &, double r, int n) noexcept
{
    cout << "Rezerw. new[] (size_t rozmiar, const nothrow_t &, bool stan), gdzie rozmiar = " << rozmiar
         << ", " << r << ", " << n << endl;
    //nasze dodatkowe akcje
    //TEST_NIEPOWODZENIA
    return (::new(nothrow) char[rozmiar]);
}

void *Twektorek::operator new[](size_t rozmiar, const nothrow_t &) noexcept
{
    cout << "Rezerw. new[] (size_t rozmiar,  const nothrow_t &), rozmiar = " << rozmiar << endl;
    //nasze dodatkowe akcje
    //TEST_NIEPOWODZENIA
    return (::new(nothrow) char[rozmiar]);
}