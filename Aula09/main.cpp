#include <iostream>
#include "Pedido.h"

using namespace std;

int main()
{
    Pedido p1("Joao", 3);
    Pedido p2("Maria", 2);
    Pedido p3;

    cout << "Pedido " << p1.GetID() << " de " << p1.GetNome() << " com " << p1.GetNmroItens() << " itens." << endl;
    cout << "Pedido " << p2.GetID() << " de " << p2.GetNome() << " com " << p2.GetNmroItens() << " itens." << endl;
    cout << "Pedido " << p3.GetID() << " de " << p3.GetNome() << " com " << p3.GetNmroItens() << " itens." << endl;

    p1.SetItem(0, "Arroz");
    p1.SetItem(1, "Feijao");
    p1.SetItem(2, "Carne");

    string item;
    for (int i = 0; i < p1.GetNmroItens(); i++)
    {
        p1.GetItem(i, item);
        cout << "Item " << i << ": " << item << endl;
    }

    cout << "Total de pedidos: " << Pedido::GetContPedidos() << endl;
    cout << "Total de itens: " << Pedido::GetContItens() << endl;

    return 0;
}