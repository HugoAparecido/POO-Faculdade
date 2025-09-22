#include "Produto.h"

class Estoque
{
public:
    Estoque(int tamanho_inicial = 10);
    bool AdicionarProduto(const Produto &produto);
    bool RemoverProduto(const string &nome);
    bool BuscarProduto(const string &nome, Produto &produto) const;
    ~Estoque();

private:
    Produto *produtos;
    int tamanho;
};