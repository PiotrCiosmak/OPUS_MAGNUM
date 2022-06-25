#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream osrodek("mars.tmp");
    //osrodek.open("mars.tmp");
    osrodek<<"misja";
    osrodek.close();
}