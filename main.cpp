#include <iostream>

using namespace std;

class Tdrzwi
{
    Tdrzwi() = delete;

    int a;
public:
    Tdrzwi(int a)
    {
        this->a = a;
    }
};

class Topona
{
    int z;
public:
    Topona(int i)
    {
        z = i;
    }
};

class Tsamochod
{
    Tdrzwi lewe, prawe;
    bool ifElectric;

    Tsamochod() : lewe{1}, prawe{2}, ifElectric{false}
    {
        //dalesze ciało
    }

    Topona tablica[4]{Topona(1), Topona(2), Topona(3), Topona(4)};
};

int main()
{

}