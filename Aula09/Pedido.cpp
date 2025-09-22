#include "Pedido.h"

unsigned int Pedido::cont_itens = 0;
unsigned int Pedido::cont_pedidos = 0;
unsigned int Pedido::prox_id = 1;

Pedido::Pedido(string nome = "desconhecido", int qtdItens = 0) : id(prox_id++)
{
    this->nome = nome;
    nmroItens = (qtdItens > 0) ? qtdItens : 0;
    ptrItens = new string[nmroItens];
    cont_pedidos++;
    cont_itens += qtdItens;
    for (int i = 0; i < this->nmroItens; i++)
        ptrItens[i] = "---";
}

int Pedido::GetID() const
{
    return id;
}

string Pedido::GetNome() const
{
    return nome;
}

int Pedido::GetNmroItens() const
{
    return nmroItens;
}

bool Pedido::SetItem(int pos, string val)
{
    if (pos >= 0 && pos < nmroItens)
    {
        ptrItens[pos] = val;
        return true;
    }
    return false;
}

bool Pedido::GetItem(int pos, string &val) const
{
    if (pos >= 0 && pos < nmroItens)
    {
        val = ptrItens[pos];
        return true;
    }
    return false;
}

int Pedido::GetContPedidos()
{
    return cont_pedidos;
}

int Pedido::GetContItens()
{
    return cont_itens;
}

Pedido::~Pedido()
{
    cont_itens -= nmroItens;
    cont_pedidos--;
    delete ptrItens;
}