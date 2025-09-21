#include <iostream>
#include "vendedor.h"

int main()
{
    vendedor vendedor1(123456789, "joao da silva", "loja A", 2000.00, 135);
    cout << "Salario: " << vendedor1.GetSalario() << endl;
    cout << "Numero de vendas: " << vendedor1.GetNumeroVendas() << endl;
    cout << "Renda com comissao: " << vendedor1.GetRenda() << endl;

    const vendedor vendedor2(987654321, "maria de souza", "loja B", 3000.00, 50);
    cout << "Salario: " << vendedor2.GetSalario() << endl;
    cout << "Renda: " << vendedor2.GetRenda() << endl;

    return 0;
}