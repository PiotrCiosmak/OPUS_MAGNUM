#include <iostream>

using namespace std;

int main()
{
    // W instrukcji sterującej switch() jako wartośc stałą po instrukcji case możemy postawić bardziej skąplikowane wyrażenie mające cechę constexpr

    /* Należy użyć if...else zamiast switch gdy:
     * - obiekt porównany nie jest typu całkowitego (ani takiego, który na typ całkowity kompilator potrafi zamienić)
     * - operacją porównania inną niż "czy a jest równe b"
     * - to, z czym porównujemy, nie jest wartością stałą znaną już w czasie kompilacji
    */

    // Instrukcja break powoduje przerwanie pętli w ktorej się znajduję

    // Instrukcja continue powoduje zaniechanie wykonywania instrukcji będących dalszą treścią danego obiegu pętli, jednak (w przeciwieństwie do instrukcji break)
    // sama pętla nie zostaje przerwana. przerwany zostaje tylko ten aktualny obieg pętli, odrazu rozpoczyna się kolejna iteracja pętli
}