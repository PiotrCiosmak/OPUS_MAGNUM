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
    if(wsk != nullptr)
    {
        cout<<"Odwolanie rezerw. delete[](void *wsk, size_t rozmiar), rozmiar = "<<rozmiar<<endl;
        ::delete[] static_cast<char*>(wsk);
    }
}