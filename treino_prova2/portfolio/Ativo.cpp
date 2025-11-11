#include "Ativo.h"

#include <string.h>

Ativo::Ativo(std::string ticker, double precoMedioCompra, int quantidade)
{
    this->ticker = ticker;
    this->precoMedioCompra = precoMedioCompra > 0 ? precoMedioCompra : 0;
    this->quantidade = quantidade > 0 ? quantidade : 0;
}

double Ativo::GetValorTotal() const
{
    return precoMedioCompra * quantidade;
}

std::string Ativo::GetTicker() const
{
    return ticker;
}

double Ativo::GetPrecoMedioCompra() const
{
    return precoMedioCompra;
}

int Ativo::GetQuantidade() const
{
    return quantidade;
}