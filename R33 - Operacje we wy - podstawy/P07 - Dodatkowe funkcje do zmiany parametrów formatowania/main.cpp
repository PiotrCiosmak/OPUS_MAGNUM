#include <iostream>

using namespace std;

int main()
{
    int liczba{107};
    cout << "Wypis [" << liczba << "]\nWypis [";
    cout.width(7);
    cout << liczba << "]" << endl;
}