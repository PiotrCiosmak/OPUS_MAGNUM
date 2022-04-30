#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    auto wypisz = [](double s) { cout << "Lambda 'wypisz': s = " << s << endl; };
    wypisz(8.7);
    wypisz(2000.5);

    vector<int> v{4, 2, 13, 24};
    cout << "Wyslanie tego wyrazenia lambda do algorytmu for_each" << endl;
    for_each(v.begin(), v.end(), wypisz);
}