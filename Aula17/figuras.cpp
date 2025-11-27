// Arthur Henrique Braz 832132
// Gustavo Amadeu Mancuzo de Sylos 845572
// Gustavo Gomes Nielsen, 847560
// Hugo Aparecido Gregorio de almeida 844917

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <chrono>
#include <thread>
#include <random>

using std::cout;
using std::endl;
using std::string;
using std::to_string;

#define ROW 5
#define COL 9

template <size_t R, size_t C> // necessário para manipular matrizes
// printa no terminal a matriz
void printMatrix(const string (&matrix)[R][C]){ 
    cout << "   ";
    for (size_t i = 0; i < C; i++){
        cout << " "<< i << " ";
    }

    cout << "\n";

    for (size_t i = 0; i < R; i++){
        cout << " "<< i << " ";
        for (size_t j = 0; j < C; j++){
            cout << "[" << matrix[i][j] << "]";
        }
        cout << "\n";
    }

    cout << "\n <======================>\n\n";
};


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

void DisplayRefresh(const vector<Figura*> &vetor_fig) {
    // apaga todo o terminal
    cout << "\033[2J\033[1;1H";

    for (Figura* fig : vetor_fig) {
        fig->Desenha();
    }
}

int random_posicao_X(){
    // motor de geração de números aleatórios cuja seed é o tempo
    static mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(-25, 25); // intervalo
    return dist(rng);
}
int random_posicao_Y(){
    // motor de geração de números aleatórios cuja seed é o tempo
    static mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(-25, 25); // intervalo
    return dist(rng);
}

int main() {
    // alocação de memória e criação do vetor de figuras
    vector<Figura*> vetor_figuras;
    vetor_figuras.push_back(new circulo());
    vetor_figuras.push_back(new quadrado());
    vetor_figuras.push_back(new triangulo());
    vetor_figuras.push_back(new estrela());

    while (true) {
        // atualiza as posições randomicamente
        for (Figura* fig : vetor_figuras) {
            fig->SetPosicao(random_posicao_X(),random_posicao_Y());
        }
        
        // limpa o terminal e desenha as figuras
        DisplayRefresh(vetor_figuras, vetor_figuras.size());

        // aguarda 5 segundos antes de repetir o processo
        this_thread::sleep_for(chrono::seconds(5));
    }

    return 0;
}