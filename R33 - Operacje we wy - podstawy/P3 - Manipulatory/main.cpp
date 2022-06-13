#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << "1.\n";
    bool logika{true};
    cout << "gdy domniemanie: " << logika
         << ", po boolalpha: " << boolalpha << logika
         << ", po noboolalpha: " << noboolalpha << logika << endl << endl;

    cout << "2.\n";
    int i{30};
    cout << "Dziesiatkowo " << dec << i
         << ", szesnastkowo " << hex << i
         << ", osemkowo " << oct << i << endl << endl;

    cout << "3.\n";
    cout << "wypis linii 1" << flush
         << "wypis linii 2" << flush << endl << endl;

    cout << "4.\n";
    int value{-1234};
    double p{-99.5432};
    cout << right;
    cout << "#" << setw(15) << value << "# [" << setw(24) << scientific << p << "]" << endl;
    cout << left;
    cout << "#" << setw(15) << value << "# [" << setw(24) << p << "]" << endl;
    cout << internal;
    cout << "#" << setw(15) << value << "# [" << setw(24) << p << "]" << endl << endl;

    cout << "5.\n";
    int kwota{10};
    cout << "Stan konta: " << setfill('*') << setw(9) << kwota << "$" << endl << endl;

    cout << "6.\n";
    double x{99.123456789};
    cout << fixed << x << "\t" << setprecision(2) << x << "\t" << setprecision(8) << x << endl << endl;

    cout << "7.\n";
    int liczba{242};
    cout << hex << liczba << ", "
         << setiosflags(ios::uppercase) << liczba << ", "
         << resetiosflags(ios::uppercase) << liczba << endl << endl;

}