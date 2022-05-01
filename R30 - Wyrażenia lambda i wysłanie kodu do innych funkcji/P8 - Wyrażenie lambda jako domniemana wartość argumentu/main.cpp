#include <iostream>
#include <functional>

using namespace std;

void trajektoria(int m, std::function<double(double)> operacja_matematyczna = [](double arg)
{
    cout << "DOMNIEMANA (negacja)" << endl;
    return -arg;
});

double zwykla(double x);

int main()
{
    int wykladnik{5};
    trajektoria(4, [wykladnik](double x)
    {
        cout << "Lambda potegujace, przechwycone = " << wykladnik << endl;
        double rezultat{1};
        for (int w = 0; w < wykladnik; ++w)
            rezultat *= x;
        return rezultat;
    });

    trajektoria(40);
}

void trajektoria(int m, std::function<double(double)> operacja_matematyczna)
{
    cout << "trajektoria(" << m << ")";
    if (operacja_matematyczna == nullptr)
        return;

    cout << " wykonuje lambde:\n\t";
    double wynik = operacja_matematyczna(m);

    cout << "\twynik operacji: " << wynik << endl;
}