#include <iostream>
#include "vendedor.h"

using namespace std;

int main()
{
    Vendedor vendedor1(123456789, "Joao Silva", "Loja A", 2000.0);
    vendedor1.Venda(150, vendedor1.GetRenda());
    cout << "CNPJ: " << vendedor1.GetCNPJ() << endl;
    cout << "Nome: " << vendedor1.GetNome() << endl;
    cout << "Loja Afiliada: " << vendedor1.GetLoja_afiliada() << endl;
    cout << "Numero de Vendas: " << vendedor1.GetNumeroVendas() << endl;
    cout << "Renda com Comissao: " << vendedor1.GetRenda() << endl;
    return 0;
}