#include "Investidor.h"

#include <iostream>

Investidor::Investidor(std::string nome = "", std::string cpf = "")
{
    this->nome = nome;
    this->cpf = cpf;
}

void Investidor::ExibirInfo() const
{
    std::cout << "Nome: " << nome << "; CPF: " << cpf << ";" << std::endl;
}