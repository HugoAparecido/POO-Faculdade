#include "Produto.h"

Produto::Produto(string nome, double preco, int quantidade)
{
    this->nome = nome;
    this->preco = (preco >= 0.0) ? preco : 0.0;
    SetQuantidade(quantidade);
}

// Getters
string Produto::GetNome() const
{
    return nome;
}
double Produto::GetPreco() const
{
    return preco;
}
int Produto::GetQuantidade() const
{
    return quantidade;
}
// Setters
void Produto::SetQuantidade(int quantidade)
{
    this->quantidade = (quantidade >= 0) ? quantidade : 0;
}

double Produto::IMPOSTO_PADRAO = 0.10;
double Produto::CalcularImpostoTotal(double preco)
{
    double imposto_sobre_preco = preco * Produto::IMPOSTO_PADRAO;
}

double Produto::calcularPrecoComImposto() const
{
    return preco + CalcularImpostoTotal(preco);
}

Produto::~Produto()
{
}