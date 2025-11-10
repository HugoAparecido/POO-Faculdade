#ifndef FIGURA
#define FIGURA

#include <string>
#include <iostream>

using std::string;

class Figura
{
private:
    string nome;

public:
    Figura(string nome);
    virtual ~Figura() = default;
    virtual double CalcularArea() const = 0;
    virtual double CalcularPerimetro() const = 0;
    virtual void ExibirInfo() const = 0;
    string GetNome() const;
    friend std::ostream &operator<<(std::ostream &output, const Figura &fracao);
    double operator+(const Figura &figDir) const;
    bool operator==(const Figura &figDir) const;
    bool operator>(const Figura &figDir) const;
};

#endif