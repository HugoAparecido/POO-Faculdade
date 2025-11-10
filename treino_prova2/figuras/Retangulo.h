#ifndef RETANGULO
#define RETANGULO

#include "Figura.h"

class Retangulo : public Figura
{
private:
    double base;
    double altura;
    void SetBase(double base);
    void SetAltura(double altura);

public:
    Retangulo(double base, double altura);
    Retangulo(double lado);
    double GetBase() const;
    double GetAltura() const;
    double CalcularArea() const override;
    double CalcularPerimetro() const override;
    void ExibirInfo() const override;
    void Redimensionar(double fator);
    void Redimensionar(double novaBase, double novaAltura);
};

#endif