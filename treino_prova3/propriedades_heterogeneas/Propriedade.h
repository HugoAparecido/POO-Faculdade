#ifndef PROPRIEDADE
#define PROPRIEDADE

#include "PropriedadeBase.h"
#include <iostream>

template <typename T>
class Propriedade : public PropriedadeBase
{
private:
    T valor;
    std::string nome;

public:
    Propriedade(std::string nome, T valor) : nome(nome), valor(valor) {};

    void exibirDetalhes() const override
    {
        std::cout << "Propriedade: " << nome << " = " << valor << std::endl;
    }
};

template <>
class Propriedade<bool> : public PropriedadeBase
{
private:
    std::string nome;
    bool valor;

public:
    Propriedade(std::string nome, bool valor)
    {
        this->nome = nome;
        this->valor = valor;
    };

    void exibirDetalhes() const override
    {
        std::cout << "Propriedade: " << nome << " = " << (valor ? "Verdadeiro" : "Falso") << std::endl;
    };
};

#endif