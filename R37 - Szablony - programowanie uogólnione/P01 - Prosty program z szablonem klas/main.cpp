//
// Created by MrChi on 18.09.2022.
//
#include <iostream>
#include "TSchowek.hpp"
using namespace std;

int main()
{
    TSchowek<double> g;
    g.schowaj(9.81);
    double wart = g.oddaj();
    cout<<"Wartosc wyjeta z czynnika g = "<<wart<<endl;

    TSchowek<string> tekstowy;
    tekstowy.schowaj("Ogary poszly w las z radosnym psim halasem");
    cout<<"W schowku tekstowym = "<<tekstowy.oddaj()<<endl;

    TSchowek<string> podpis;
    podpis.schowaj("Jeremi P.");
}