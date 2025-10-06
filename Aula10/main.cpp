#include <iostream>
#include "Roteiro.h"

using namespace std;

int main()
{
    Roteiro r1("Europa", 3, 2500.00);
    Roteiro::SetCotacao(5.25);
    cout << "Roteiro: " << r1.GetNome() << endl;
    cout << "Valor em dolares: " << r1.GetValorDolar() << endl;
    cout << "Valor em reais: " << r1.GetValorReais() << endl;
    cout << "Numero de paises: " << r1.GetNmroPaises() << endl;

    r1.SetPais(0, "Franca");
    r1.SetPais(1, "Italia");
    r1.SetPais(2, "Inglaterra");

    string pais;
    for (int i = 0; i < r1.GetNmroPaises(); i++)
    {
        if (r1.GetPais(i, pais))
            cout << "Pais[" << i << "] = " << pais << endl;
        else
            cout << "Pais[" << i << "] invalido!" << endl;
    }

    return 0;
}