#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    char znak;
    do
    {
        cin >> znak;
        cout << znak;
    } while (cin.good());
}