#include <iostream>

using namespace std;

class TportA
{
public:
    unsigned int odczyt: 1;
    unsigned int tryb: 2;
    unsigned int gotow: 1;
    unsigned int dana: 4;
    //W sumie 8 bitów czyli 1 bajt
};

int main()
{
    TportA obj;
    obj.dana = 1;
    cout << obj.dana << endl;
}