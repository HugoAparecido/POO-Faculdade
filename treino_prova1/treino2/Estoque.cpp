#include "Estoque.h"

using namespace std;

Estoque::Estoque(int tamanho_inicial)
{
    if (tamanho_inicial <= 0)
        this->tamanho = 10;
    else
        this->tamanho = tamanho_inicial;
    produtos = new Produto[this->tamanho];
    for (int i = 0; i < this->tamanho; i++)
        produtos[i] = Produto(); // Inicializa com produtos vazios
}

bool Estoque::AdicionarProduto(const Produto &produto)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (produtos[i].GetQuantidade() == 0) // Encontrar a primeira posicao vazia
        {
            produtos[i] = produto;
            return true;
        }
    }
    return false; // Estoque cheio
}

bool Estoque::RemoverProduto(const string &nome)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (produtos[i].GetNome() == nome)
        {
            produtos[i].SetQuantidade(0); // Marca como removido
            return true;
        }
    }
    return false; // Produto nao encontrado
}

bool Estoque::BuscarProduto(const string &nome, Produto &produto) const
{
    for (int i = 0; i < tamanho; i++)
    {
        if (produtos[i].GetNome() == nome)
        {
            produto = produtos[i];
            return true;
        }
    }
    return false; // Produto nao encontrado
}

Estoque::~Estoque()
{
    delete[] produtos;
}