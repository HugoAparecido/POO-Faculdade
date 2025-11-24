#include <iostream>

using std::string;

class Figura
{
public:
    void SetPosicao(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    virtual void Desenha() const = 0;
    int GetX()
    {
        return x;
    }
    int GetY()
    {
        return y;
    };
    string GetPosicao() const
    {
        return "(" + x + ',' + y + ")";
    };
    virtual ~Figura() {};

private:
    int x;
    int y;
};

class Circulo : Figura
{
public:
    Circulo(int x, int y, int raio)
    {
        SetPosicao(x, y);
        this->raio = raio;
    }
    void Desenha() {}

private:
    int raio;
};

class Quadrado : Figura
{
public:
    Quadrado(int x, int y, int lado)
    {
        SetPosicao(x, y);
        this->lado = lado;
    };
    void Desenha() {};

private:
    int lado;
};

class Triangulo : Figura
{
public:
    Triangulo(int x, int y, int base, int altura)
    {
        SetPosicao(x, y);
        this->base = base;
        this->altura = altura;
    };
    void Desenha() {};

private:
    int base;
    int altura;
};

int main()
{
    return 0;
}