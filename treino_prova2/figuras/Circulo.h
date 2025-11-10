#ifndef CIRCULO
#define CIRCULO

#include "Figura.h"

class Circulo : public Figura
{
private:
    double raio;
    void SetRaio(double raio);

public:
    Circulo(double raio);
    double GetRaio() const;
    double CalcularArea() const override;
    double CalcularPerimetro() const override;
    void ExibirInfo() const override;
};

#endif
