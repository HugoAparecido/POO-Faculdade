#include <iostream>
#include "Produto.h"

using namespace std;

int main()
{
    const Produto produto("Caneta", 2.0, 100);
    cout << "Nome: " << produto.GetNome() << endl;
    cout << "Preco: " << produto.GetPreco() << endl;
    cout << "Quantidade: " << produto.GetQuantidade() << endl;
    cout << "Preco com imposto: " << produto.calcularPrecoComImposto() << endl;
    cout << "Imposto total de 10 reais: " << Produto::CalcularImpostoTotal(10.0) << endl;
    return 0;
}