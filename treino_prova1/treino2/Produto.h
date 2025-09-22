#include <string>

using namespace std;

class Produto
{
public:
    Produto(string nome = "", double preco = 0.0, int quantidade = 0);
    // Getters
    string GetNome() const;
    double GetPreco() const;
    int GetQuantidade() const;
    // Setters
    void SetQuantidade(int quantidade);
    static double CalcularImpostoTotal(double preco);
    double calcularPrecoComImposto() const;
    ~Produto();

private:
    string nome;
    double preco;
    int quantidade;
    static double IMPOSTO_PADRAO;
};