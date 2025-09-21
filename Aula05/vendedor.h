#include <string>

using namespace std;

class Vendedor
{
public:
    Vendedor(int CNPJ, string Nome, string Loja_afiliada, double Renda);
    // Setters
    void SetCNPJ(int cnpj);
    void SetNome(string nome);
    void SetLoja_afiliada(string loja_afiliada);
    void SetRenda(double renda);
    void SetNumeroVendas(int numero_vendas);
    // Getters
    int GetCNPJ();
    string GetNome();
    string GetLoja_afiliada();
    double GetRenda();
    int GetNumeroVendas();
    void Venda(int numero_vendas, double renda);

private:
    int CNPJ;
    string Nome;
    string Loja_afiliada;
    double Renda;
    int Numero_vendas;
    bool ValidaCNPJ(int cnpj);
    double Comissao(int numero_vendas, double renda);
};