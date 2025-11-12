#include "Complexo.h"

Complexo::Complexo(double real, double imag)
{
    this->real = real;
    this->imag = imag;
}

double Complexo::GetReal() const
{
    return real;
}

double Complexo::GetImag() const
{
    return imag;
}

void Complexo::Set(double r, double i)
{
    real = r;
    imag = i;
}

void Complexo::Somar(const Complexo &outro)
{
    this->real += outro.GetReal();
    this->imag += outro.GetImag();
}

void Complexo::Somar(double r)
{
    this->real += r;
}

void Complexo::Imprimir() const
{
    std::cout << GetReal() << " " << (imag >= 0 ? "+" : "-") << " " << (GetImag() >= 0 ? imag : (imag * (-1))) << "i";
}

const Complexo Complexo::operator++(int)
{
    Complexo temp(*this);
    real++;
    return temp;
}

Complexo &Complexo::operator++()
{
    real++;
    return *this;
}

const Complexo Complexo::operator--(int)
{
    Complexo temp(*this);
    real--;
    return temp;
}

Complexo &Complexo::operator--()
{
    real--;
    return *this;
}

const Complexo Complexo::operator+(const Complexo &outro) const
{
    Complexo temp(*this);
    temp.Somar(outro);
    return temp;
}

const Complexo Complexo::operator-(const Complexo &outro) const
{
    Complexo temp(*this);
    temp.Set(temp.GetReal() - outro.GetReal(), temp.GetImag() - outro.GetImag());
    return temp;
}

const Complexo Complexo::operator*(const Complexo &outro) const
{
    Complexo temp(*this);
    double parteReal = (temp.GetReal() * outro.GetReal() - temp.GetImag() * outro.GetImag());
    double parteImag = (temp.GetReal() * outro.GetImag() + temp.GetImag() * outro.GetReal());
    temp.Set(parteReal, parteImag);

    return temp;
}

bool Complexo::operator==(const Complexo &outro) const
{
    return (this->GetReal() == outro.GetReal() && this->GetImag() == outro.GetImag());
}

bool Complexo::operator!=(const Complexo &outro) const
{
    return !(*this == outro);
}

std::ostream &operator<<(std::ostream &os, const Complexo &c)
{
    c.Imprimir();
    return os;
}

std::istream &operator>>(std::istream &is, Complexo &c)
{
    std::cout << "Valor real:";
    double real;
    std::cin >> real;
    std::cout << "Valor imaginario:";
    double imag;
    std::cin >> imag;
    c.Set(real, imag);
    return is;
}
