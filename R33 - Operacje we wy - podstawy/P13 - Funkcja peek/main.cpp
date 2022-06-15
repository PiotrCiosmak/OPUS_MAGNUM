#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    char nazwa[200];
    double x;
    int zwiastun;
    cout << "napisz liczbe lub nazwe:";
    zwiastun = cin.peek();

    if (isdigit(zwiastun))
    {
        cin >> x;
        cout << "Byla to lliczba: " << x << endl;
    }
    else
    {
        cin >> nazwa;
        cout << "Byla to nazwa: " << nazwa << endl;
    }
}