#include <iostream>

using namespace std;

class Aluno
{
public:
    Aluno(string nome, int qtdeNotas, double *notas);
    ~Aluno();
    void SetNome(string nome);
    string GetNome() const;
    int GetRA() const;
    bool SetNotas(int qtdeNotas, double *notas);
    bool GetNota(double *notas) const;
    void SetQtdNotas(int qtdeNotas);
    int GetQtdNotas(int pos, double &val) const;
    static void IncrementarContador();
    void ImprimeTodasNotas() const;

private:
    static int contador;
    const int RA;
    string nome;
    int qtdeNotas;
    double *notas;
}

Aluno::Aluno(string nome, int qtdeNotas, double *notas):RA(++Aluno::contador){
    this->SetNome(nome);
    this->SetQtdNotas(qtdeNotas);
    this->SetNotas(qtdeNotas);
}

Aluno::~Aluno(){
    if(this->notas != NULL)
    delete this->notas;
}

int main()
{
}