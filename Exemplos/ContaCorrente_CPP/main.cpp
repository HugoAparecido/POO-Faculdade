#include <iostream>
#include "ContaCorrente.h"

using namespace std;

int main()
{

    // Alocação Estática
    ContaCorrente c1(1, 1200.50);
    ContaCorrente c2(2);

    // Alocação Dinâmica
    ContaCorrente *c3 = new ContaCorrente(3, 1000);

    cout << endl
         << "Antes da Transferência" << endl
         << endl;

    c1.imprime();
    c2.imprime();
    c3->imprime();

    c1.transferencia(c2, 500);

    cout << endl
         << "Depois da Transferência" << endl
         << endl;

    c1.imprime();
    c2.imprime();
    c3->imprime();

    cout << endl;

    delete c3;

    return 0;
}
