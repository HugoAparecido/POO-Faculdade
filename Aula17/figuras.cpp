#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using std::cout;
using std::endl;
using std::string;
using std::to_string;

class Figura
{
public:
    virtual ~Figura() {}

    void SetPosicao(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    virtual void Desenha() const = 0;
    virtual double GetArea() const = 0;
    virtual double GetPerimetro() const = 0;

    int GetX() const { return x; }
    int GetY() const { return y; }

    string GetPosicao() const
    {
        return "(" + to_string(x) + ", " + to_string(y) + ")";
    }

private:
    int x;
    int y;
};

// ============================================================================
// COMO ADICIONAR UMA NOVA FIGURA
// ============================================================================
/*
    Para criar um novo tipo de figura (ex: Hexagono, Elipse), siga este modelo:

    1. Declare a classe herdando publicamente de Figura:
       class NovaForma : public Figura { ... }

    2. Crie os atributos privados específicos da forma (ex: raio_maior, angulo).

    3. No construtor, receba X e Y + atributos e chame SetPosicao:
       NovaForma(int x, int y, int atributo) {
           SetPosicao(x, y);       // Configura a base
           this->atributo = atributo; // Configura o específico
       }

    4. Implemente os  método Desenha obrigatoriamente:
       void Desenha() const {
           // Lógica da impressão
       }

        double GetArea() const
        {
            // Cálculo da área
        }

        double GetPerimetro() const{
            // Cálculo do perímetro
        }

    Exemplo Rápido de Template:

    class MinhaNovaFigura : public Figura
    {
    public:
        MinhaNovaFigura(int x, int y, int tamanho) {
            SetPosicao(x, y);
            this->tamanho = tamanho;
        }

        void Desenha() const override {
             cout << "Nova Figura em " << GetPosicao()
                  << " com tamanho " << tamanho << endl;
        }
    private:
        int tamanho;
    };
*/
// ============================================================================

class Circulo : public Figura
{
public:
    Circulo(int x, int y, int raio)
    {
        SetPosicao(x, y);
        this->raio = raio;
    }

    void Desenha() const override
    {
        cout << "Desenhando Circulo(O) em " << GetPosicao()
             << " com raio " << raio << endl;
    }

    double GetArea() const
    {
        return 3.14 * raio * raio;
    }

    double GetPerimetro() const
    {
        return 2 * 3.14 * raio;
    }

private:
    int raio;
};

class Quadrado : public Figura
{
public:
    Quadrado(int x, int y, int lado)
    {
        SetPosicao(x, y);
        this->lado = lado;
    }

    void Desenha() const override
    {
        cout << "Desenhando Quadrado([]) em " << GetPosicao()
             << " com lado " << lado << endl;
    }

    double GetArea() const
    {
        return lado * lado;
    }

    double GetPerimetro() const
    {
        return 4 * lado;
    }

private:
    int lado;
};

class Triangulo : public Figura
{
public:
    Triangulo(int x, int y, int base, int altura)
    {
        SetPosicao(x, y);
        this->base = base;
        this->altura = altura;
    }

    void Desenha() const override
    {
        cout << "Desenhando Triangulo(^) em " << GetPosicao()
             << " com base " << base << " e altura " << altura << endl;
    }

    double GetArea() const
    {
        return (base * altura) / 2;
    }

    double GetPerimetro() const
    {
        double hipotenusa = sqrt(pow(base, 2) + pow(altura, 2));
        return base + 2 * hipotenusa;
    }

private:
    int base;
    int altura;
};

int main()
{
    std::vector<Figura *> figuras;

    figuras.push_back(new Circulo(10, 20, 5));
    figuras.push_back(new Quadrado(5, 5, 10));
    figuras.push_back(new Triangulo(0, 0, 8, 4));

    cout << "--- Renderizando Figuras ---" << endl;

    for (Figura *fig : figuras)
    {
        fig->Desenha();
    }

    for (Figura *fig : figuras)
    {
        delete fig;
    }
    figuras.clear();

    return 0;
}