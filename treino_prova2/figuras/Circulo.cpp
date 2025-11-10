#include "Circulo.h"
#include <cmath>
#include <iostream>

void Circulo::SetRaio(double raio)
{
    this->raio = (raio > 0) ? raio : 0;
}

Circulo::Circulo(double raio) : Figura("Circulo")
{
    SetRaio(raio);
}

double Circulo::GetRaio() const
{
    return raio;
}

double Circulo::CalcularArea() const
{
    return M_PI * pow(raio, 2);
}

double Circulo::CalcularPerimetro() const
{
    return 2 * M_PI * raio;
}

void Circulo::ExibirInfo() const
{
    std::cout << GetNome() << " de raio: " << GetRaio();
}