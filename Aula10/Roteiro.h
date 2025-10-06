#include <string>

using namespace std;

class Roteiro
{
public:
    Roteiro(string nome = "", int nmro_paises = 0, double valor = 0.0);
    bool SetPais(int pos, string val);
    bool GetPais(int pos, string &val) const;
    void SetValor(double v);
    static double GetCotacao();
    static void SetCotacao(double v);
    string GetNome() const;
    double GetValorDolar() const;
    double GetValorReais() const;
    int GetNmroPaises() const;
    ~Roteiro();

private:
    string nome;
    int nmro_paises;
    string *ptr_paises;
    double valor;
    static double cotacao;
};