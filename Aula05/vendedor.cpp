#include <iostream>
#include "vendedor.h"

using namespace std;

Vendedor::Vendedor(int cnpj, string nome, string loja_afiliada, double renda)
{
    SetCNPJ(cnpj);
    SetNome(nome);
    SetLoja_afiliada(loja_afiliada);
    SetRenda(renda);
    SetNumeroVendas(0);
}

void Vendedor::SetCNPJ(int cnpj)
{
    if (ValidaCNPJ(cnpj))
        this->CNPJ = cnpj;
    else
        this->CNPJ = 0;
}

bool Vendedor::ValidaCNPJ(int cnpj)
{
    return (cnpj > 0);
}

void Vendedor::SetNome(string nome)
{
    Nome = nome;
}

void Vendedor::SetLoja_afiliada(string loja_afiliada)
{
    Loja_afiliada = loja_afiliada;
}

void Vendedor::SetRenda(double renda)
{
    Renda = (renda >= 0) ? renda : 0;
}

void Vendedor::SetNumeroVendas(int numero_vendas)
{
    Numero_vendas = (numero_vendas >= 0) ? numero_vendas : 0;
}

int Vendedor::GetCNPJ()
{
    return CNPJ;
}

int Vendedor::GetNumeroVendas()
{
    return Numero_vendas;
}

double Vendedor::GetRenda()
{
    return Renda;
}

string Vendedor::GetNome()
{
    return Nome;
}

string Vendedor::GetLoja_afiliada()
{
    return Loja_afiliada;
}

double Vendedor::Comissao(int numero_vendas, double salario)
{
    if (numero_vendas < 100)
        return salario * 1.05;
    else if (numero_vendas >= 100 && numero_vendas < 500)
        return salario * 1.1;
    else
        return salario * 1.15;
}

void Vendedor::Venda(int numero_vendas, double renda)
{
    SetNumeroVendas(numero_vendas);
    SetRenda(Comissao(numero_vendas, renda));
}