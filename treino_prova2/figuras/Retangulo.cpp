#include "Retangulo.h"
#include <iostream>

void Retangulo::SetBase(double base)
{
    this->base = (base > 0) ? base : 0;
}

void Retangulo::SetAltura(double altura)
{
    this->altura = (altura > 0) ? altura : 0;
}

Retangulo::Retangulo(double base, double altura) : Figura("Retangulo")
{
    SetBase(base);
    SetAltura(altura);
}

Retangulo::Retangulo(double lado) : Figura("Quadrado")
{
    SetBase(lado);
    SetAltura(lado);
}

double Retangulo::GetBase() const
{
    return base;
}

double Retangulo::GetAltura() const
{
    return altura;
}

double Retangulo::CalcularArea() const
{
    return base * altura;
}

double Retangulo::CalcularPerimetro() const
{
    return 2 * base * altura;
}

void Retangulo::ExibirInfo() const
{
    std::cout << GetNome() << " de " << GetBase() << " x " << GetAltura();
}

void Retangulo::Redimensionar(double fator)
{
    base *= (fator > 0) ? fator : 1;
    altura *= (fator > 0) ? fator : 1;
}

void Retangulo::Redimensionar(double novaBase, double novaAltura)
{
    SetBase(novaBase);
    SetAltura(novaAltura);
}