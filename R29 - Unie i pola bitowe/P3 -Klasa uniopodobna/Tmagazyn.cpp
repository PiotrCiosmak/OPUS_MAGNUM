#include "Tmagazyn.hpp"

using namespace std;

void Tmagazyn::magazyn_ma()
{
    switch (co_przechowujemy)
    {
        case nic:
            std::cout << "Magazyn jest pusty" << std::endl;
            break;
        case mamy_litere:
            std::cout << "W magazynie jest litera " << litera << std::endl;
            break;
        case mamy_liczbe:
            std::cout << "W magazynie jest liczba " << liczba << std::endl;
            break;
    }
};

void Tmagazyn::wstaw(char z)
{
    litera = z;
    co_przechowujemy = mamy_litere;
}

void Tmagazyn::wstaw(double x)
{
    liczba = x;
    co_przechowujemy = mamy_liczbe;
}