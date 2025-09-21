#include <string>

using namespace std;

class vendedor
{

public:
    vendedor(int cnpj, string nome, string loja_afiliada, double salario, int numero_vendas); // constructor
    // metodos set
    void SetCNPJ(int cnpj);
    void SetNome(string nome);
    void SetLoja_afiliada(string loja_afiliada);
    void SetSalario(double salario);
    void SetRenda(int numero_vendas, double salario);
    void SetNumeroVendas(int numero_vendas);
    // metodos get
    int GetCNPJ() const;
    string GetNome() const;
    string GetLoja_afiliada() const;
    double GetRenda() const;
    double GetSalario() const;
    int GetNumeroVendas() const;

private:
    int CNPJ;
    int Numero_vendas;
    string Nome;
    string Loja_afiliada;
    double Renda;
    double Salario;
    double comissao;
    bool ValidaCNPJ(int cnpj);
    double Comissao(int numero_vendas, double salario);
};
