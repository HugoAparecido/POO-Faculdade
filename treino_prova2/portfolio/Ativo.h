#ifndef ATIVO
#define ATIVO

#include <string>

class Ativo
{
private:
    std::string ticker;
    double precoMedioCompra;
    int quantidade;

public:
    Ativo(std::string ticker = "", double precoMedioCompra = 0, int quantidade = 0);
    double GetValorTotal() const;
    std::string GetTicker() const;
    double GetPrecoMedioCompra() const;
    int GetQuantidade() const;
};

#endif
