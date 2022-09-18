#include <iostream>

using namespace std;

template<typename T>
T maksimum(T a, T b)
{
    return (a > b) ? a : b;
}

int main()
{
    int a = 44, b = 88;
    double x = 12.6, y = 67.8;
    unsigned long la = 9999987654L, lb = 456;
    cout << "wiekszy int: " << maksimum(a, b) << endl;
    cout << "wiekszy double: " << maksimum(x, y) << endl;
    cout << "wiekszy int: " << maksimum<int>(x, y) << endl;

    cout << "wiekszy long: " << maksimum(la, lb) << endl;
    cout << "wiekszy znak (kod ASCII): " << maksimum('A', 'Z') << endl;

    char (*wskfun)(char, char);
    wskfun = &maksimum;
    cout << "wiekszy kod ASCII ma: " << wskfun('k', 'm');
}