#include "Roteiro.h"

double Roteiro::cotacao = 0.0;

double Roteiro::GetCotacao()
{
    return Roteiro::cotacao;
}

void Roteiro::SetCotacao(double v)
{
    Roteiro::cotacao = v;
}

Roteiro::Roteiro(string nome, int nmro_paises, double valor)
{
    this->nome = nome;
    this->nmro_paises = (nmro_paises > 0) ? nmro_paises : 0;
    this->valor = (nmro_paises > 0) ? nmro_paises : 0;
    if (this->nmro_paises == 0)
        ptr_paises = NULL;
    else
        ptr_paises = new string[this->nmro_paises];
}

bool Roteiro::SetPais(int pos, string val)
{
    if (pos < 0 || pos >= nmro_paises)
        return false;
    else
    {
        ptr_paises[pos] = val;
        return true;
    }
}

bool Roteiro::GetPais(int pos, string &val) const
{
    if (pos < 0 || pos >= nmro_paises)
        return false;
    else
    {
        val = ptr_paises[pos];
        return true;
    }
}

void Roteiro::SetValor(double v)
{
    valor = (v > 0) ? v : 0;
}

string Roteiro::GetNome() const
{
    return nome;
}

double Roteiro::GetValorDolar() const
{
    return valor;
}

double Roteiro::GetValorReais() const
{
    return (valor * Roteiro::GetCotacao());
}

int Roteiro::GetNmroPaises() const
{
    return nmro_paises;
}

Roteiro::~Roteiro()
{
    if (ptr_paises == nullptr)
        delete[] ptr_paises;
}