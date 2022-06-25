#include <iostream>
#include <limits>
#include <iomanip>
#include <string>

using namespace std;

template<typename T>
void info_o_typie(string opis)
{
    cout << setw(18) << opis << ":"
         << setw(2) << sizeof(T) << "|"
         << setw(2) << numeric_limits<T>::digits
         << (numeric_limits<T>::is_signed ? "|zn|" : "|bz|")
         << "[" << numeric_limits<T>::min()
         << ", " << numeric_limits<T>::max()
         << "]" << endl;
}

int main()
{
    info_o_typie<short int>("short int");
    info_o_typie<signed short int>("signed short int");
    info_o_typie<unsigned short int>("unsigned short int");
    info_o_typie<int>("int");
    info_o_typie<signed int>("signed int");
    info_o_typie<unsigned int>("unsigned int");
    cout << endl;
    info_o_typie<long int>("long int");
    info_o_typie<signed long>("signed long");
    info_o_typie<unsigned long>("unsigned long");
    cout << endl;
    info_o_typie<long long int>("long long int");
    info_o_typie<signed long long>("signed long long");
    info_o_typie<unsigned long long>("unsigned long long");
    cout << endl;
    info_o_typie<float>("float");
    info_o_typie<double>("double");
    info_o_typie<long double>("long double");
}