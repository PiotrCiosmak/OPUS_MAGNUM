#include <iostream>
#include <type_traits>

using namespace std;

class K
{
};

int main()
{
    if(is_pod<K>::value)
    {
        //Typ K jest POD, więc możemy użyć funkcji memcpy
    }
    else
    {
        //Typ K nie jest POD, wiec nie możemy użyć funkcji memcpy
    }
}