#include "Figura.h"
#include <iostream>
#include <cmath>

Figura::Figura(std::string nome)
{
    this->nome = nome;
}

double Figura::CalcularArea() const
{
    return 0;
}

double Figura::CalcularPerimetro() const
{
    return 0;
}

void Figura::ExibirInfo() const
{
    std::cout << "A figura tem area: " << CalcularArea() << ", e perimetro: " << CalcularPerimetro();
}

std::string Figura::GetNome() const
{
    return nome;
}

std::ostream &operator<<(std::ostream &output, const Figura &figura)
{
    figura.ExibirInfo();
    return output;
}

double Figura::operator+(const Figura &figDir) const
{
    return CalcularArea() + figDir.CalcularArea();
}

bool Figura::operator==(const Figura &figDir) const
{
    const double EPSILON = 1e-9;
    return (std::abs(CalcularArea() - figDir.CalcularArea()) < EPSILON);
}

bool Figura::operator>(const Figura &figDir) const
{
    return (CalcularPerimetro() > figDir.CalcularPerimetro());
}
