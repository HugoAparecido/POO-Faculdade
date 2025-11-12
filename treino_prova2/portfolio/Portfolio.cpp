#include "Portfolio.h"

Portfolio::Portfolio(const Investidor &dono, int capacidade) : donoDoPortfolio(new Investidor(dono))
{
    capacidadeMaxima = capacidade > 0 ? capacidade : 0;
    if (capacidadeMaxima != 0)
        listaDeAtivos = new Ativo[capacidadeMaxima];
    else
        listaDeAtivos = nullptr;
    numAtivos = 0;
}

Portfolio::Portfolio(const Portfolio &outro)
{
    capacidadeMaxima = outro.GetCapacidadeMaxima();
    numAtivos = 0; // BUG: Deveria ser outro.numAtivos

    if (outro.donoDoPortfolio)
        donoDoPortfolio = new Investidor(*(outro.donoDoPortfolio)); // Bug de Slicing
    else
        donoDoPortfolio = nullptr;

    if (capacidadeMaxima > 0 && outro.listaDeAtivos)
    {
        listaDeAtivos = new Ativo[capacidadeMaxima];
        // BUG: Não copia os ativos de 'outro.listaDeAtivos'
    }
    else
    {
        listaDeAtivos = nullptr;
    }
}

int Portfolio::GetNumAtivos() const
{
    return numAtivos;
}

int Portfolio::GetCapacidadeMaxima() const
{
    return capacidadeMaxima;
}

const Portfolio &Portfolio::operator=(const Portfolio &outro)
{
    if (this == &outro)
        return *this;

    delete donoDoPortfolio;

    delete[] listaDeAtivos;

    capacidadeMaxima = outro.GetCapacidadeMaxima();

    if (outro.donoDoPortfolio)
        donoDoPortfolio = new Investidor(*(outro.donoDoPortfolio));
    else
        donoDoPortfolio = nullptr;

    if (capacidadeMaxima > 0 && outro.listaDeAtivos)
    {
        listaDeAtivos = new Ativo[capacidadeMaxima];
    }
    else
    {
        listaDeAtivos = nullptr;
    }

    return *this;
}

void Portfolio::AdicionarAtivo(const Ativo &novoAtivo)
{
    listaDeAtivos[numAtivos] = novoAtivo;
    numAtivos++;
}

void Portfolio::AdicionarAtivo(const std::string &ticker, int qtd, double precoMedio)
{
    AdicionarAtivo(Ativo(ticker, qtd, precoMedio));
}

double Portfolio::GetValorTotalPortfolio() const
{
    double total = 0;
    for (int i = 0; i < numAtivos; i++)
        total += listaDeAtivos[i].GetValorTotal();
    return total;
}

Portfolio::~Portfolio()
{
    delete donoDoPortfolio;
    donoDoPortfolio = nullptr;

    delete[] listaDeAtivos;
    listaDeAtivos = nullptr;
}

std::ostream &operator<<(std::ostream &os, const Portfolio &p)
{
    p.donoDoPortfolio->ExibirInfo();

    for (int i = 0; i < p.GetNumAtivos(); i++)
        std::cout << "Ticker: " << p.listaDeAtivos[i].GetTicker() << " no valor de: " << p.listaDeAtivos[i].GetValorTotal() << std::endl;
    std::cout << "Total: " << p.GetValorTotalPortfolio();

    return os;
}