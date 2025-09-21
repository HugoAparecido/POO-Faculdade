#include <iostream>
#include "vendedor.h"

using namespace std;

vendedor::vendedor(int cnpj, string nome, string loja_afiliada, double salario, int numero_vendas)
{
    SetCNPJ(cnpj);
    SetNome(nome);
    SetLoja_afiliada(loja_afiliada);
    SetSalario(salario);
    SetNumeroVendas(numero_vendas);
    SetRenda(numero_vendas, salario);
}

bool vendedor::ValidaCNPJ(int cnpj)
{
    return cnpj > 0;
}

void vendedor::SetCNPJ(int cnpj)
{
    if (ValidaCNPJ(cnpj))
        CNPJ = cnpj;
    else
        CNPJ = 0;
}

void vendedor::SetNome(string nome)
{
    Nome = nome;
}

void vendedor::SetLoja_afiliada(string loja_afiliada)
{
    Loja_afiliada = loja_afiliada;
}

void vendedor::SetSalario(double salario)
{
    Salario = salario;
}

void vendedor::SetNumeroVendas(int numero_vendas)
{
    Numero_vendas = numero_vendas;
}

double vendedor::Comissao(int numero_vendas, double salario)
{
    if (numero_vendas < 100)
        return salario * 0.05;
    else if (numero_vendas < 500)
        return salario * 0.1;
    else
        return salario * 0.15;
}

void vendedor::SetRenda(int numero_vendas, double salario)
{
    comissao = Comissao(numero_vendas, salario);
    Renda = comissao + salario;
}

int vendedor::GetCNPJ() const
{
    return CNPJ;
}

string vendedor::GetNome() const
{
    return Nome;
}

string vendedor::GetLoja_afiliada() const
{
    return Loja_afiliada;
}

int vendedor::GetNumeroVendas() const
{
    return Numero_vendas;
}

double vendedor::GetSalario() const
{
    return Salario;
}

double vendedor::GetRenda() const
{
    return Renda;
}