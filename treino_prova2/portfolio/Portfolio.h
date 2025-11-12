#ifndef PORTIFOLIO
#define PORTIFOLIO

#include "Ativo.h"
#include "Investidor.h"
#include <iostream>

class Portfolio
{
private:
    Investidor *donoDoPortfolio;
    Ativo *listaDeAtivos;
    int numAtivos;
    int capacidadeMaxima;

public:
    Portfolio(const Investidor &dono, int capacidade);
    Portfolio(const Portfolio &outro);
    int GetNumAtivos() const;
    int GetCapacidadeMaxima() const;
    const Portfolio &operator=(const Portfolio &outro);
    void AdicionarAtivo(const Ativo &novoAtivo);
    void AdicionarAtivo(const std::string &ticker, int qtd, double precoMedio);
    double GetValorTotalPortfolio() const;
    friend std::ostream &operator<<(std::ostream &os, const Portfolio &p);
    ~Portfolio();
};

#endif
