#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

std::function<void(double)> lambdaG;

void fun();

int main()
{
    string wyraz{"Mars"};
    double lokmain{150};
    lambdaG = [&lokmain](char x)
    {
        lokmain++;
        cout << "Z main, element = " << x << ", a lokalna_zmienna: " << lokmain << endl;
    };
    for_each(wyraz.begin(), wyraz.end(), lambdaG);
    fun();// krytyczna linijak, lecz teoretycznie kompilator sobie z tym jakoś radzi
    for_each(wyraz.begin(), wyraz.end(), lambdaG);
}

//Aby tego uniknać należy pamiętać, że yrażenie lambda nie może przeżyć obiektów lokalnych, które wychwyciło przez referencję

void fun()
{
    int lokfun{100};
    cout << "Nowe wyrazenie lambda" << endl;
    lambdaG = [&lokfun](char x)
    {
        lokfun++;
        cout << "element = " << x << ", a lokfun: " << lokfun << endl;
    };
    //Dalsze instrukcje
}