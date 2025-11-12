#include "InvestidorQualificado.h"

#include <iostream>

InvestidorQualificado::InvestidorQualificado(std::string certificacao, std::string nome, std::string cpf) : Investidor(nome, cpf)
{
    this->certificacao = certificacao;
}

void InvestidorQualificado::ExibirInfo() const
{
    Investidor::ExibirInfo();
    std::cout << "Certifcacao: " << certificacao << std::endl;
}