#ifndef COMPLEXO
#define COMPLEXO

#include <iostream>

class Complexo
{
private:
    double real;
    double imag;

public:
    Complexo(double real = 0, double imag = 0);
    double GetReal() const;
    double GetImag() const;
    void Set(double r, double i);
    void Somar(const Complexo &outro);
    void Somar(double r);
    void Imprimir();

    const Complexo operator++(int);
    Complexo &operator++();

    const Complexo operator--(int);
    Complexo &operator--();

    const Complexo operator+(const Complexo &outro) const;
    const Complexo operator-(const Complexo &outro) const;
    const Complexo operator*(const Complexo &outro) const;
};

#endif
