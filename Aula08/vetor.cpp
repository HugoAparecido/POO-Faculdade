#include <iostream>

using namespace std;

class vetor
{
private:
    int *ptrvetor;
    int tamanho;

public:
    vetor(int tamanho_inicial = 10);
    bool set_vetor(int posicao, int valor);
    bool get_vetor(int posicao, int &valor) const;
    int get_tamanho() const;
    void print() const;
    ~vetor();
};

vetor::vetor(int tamanho)
{
    if (tamanho <= 0)
        this->tamanho = 10;
    else
        this->tamanho = tamanho;
    ptrvetor = new int[this->tamanho];
    for (int i = 0; i < this->tamanho; i++)
        ptrvetor[i] = 0;
}

bool vetor::set_vetor(int posicao, int valor)
{
    if (posicao >= 0 && posicao < tamanho)
    {
        ptrvetor[posicao] = valor;
        return true;
    }
    else
    {
        cout << "Posicao invalida!" << endl;
        return false;
    }
}

bool vetor::get_vetor(int posicao, int &valor) const
{
    if (posicao >= 0 && posicao < tamanho)
    {
        valor = ptrvetor[posicao];
        return true;
    }
    else
        return false;
}

int vetor::get_tamanho() const
{
    return this->tamanho;
}

void vetor::print() const
{
    for (int i = 0; i < tamanho; i++)
        cout << ptrvetor[i] << " ";
    cout << endl;
}

vetor::~vetor()
{
    delete[] ptrvetor;
    cout << "Destrutor chamado!" << endl;
}

int main()
{
    vetor v1(10);
    v1.set_vetor(5, 1);
    int valor;
    if (v1.get_vetor(5, valor))
        cout << valor << endl;
    v1.print();

    return 0;
}
