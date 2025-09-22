#include "aluno.h"
#include <iostream>
#include <vector>

int Aluno::contador = 0;

Aluno::Aluno(string nome, int qtdeNotas, double *notas) : RA(++Aluno::contador)
{
    // 1. Aloca a memória para as notas primeiro
    this->SetQtdNotas(qtdeNotas); 

    // 2. Agora o 'this->notas' é um ponteiro válido, e você pode usá-lo com segurança
    this->SetNome(nome);
    this->SetNotas(qtdeNotas, notas); 
}

void Aluno::SetNome(string nome)
{
    this->nome = nome;
}

string Aluno::GetNome() const
{
    return nome;
}

int Aluno::GetRA() const
{
    return RA;
}

bool Aluno::SetNotas(int qtdeNotas, double *notas)
{
    if (qtdeNotas >= 0 && notas != NULL)
    {
        for (int i = 0; i < qtdeNotas; i++)
            this->notas[i] = notas[i];
        return true;
    }
    return false;
}

bool Aluno::GetNotas(double *notas) const
{
    if (notas != NULL)
    {
        for (int i = 0; i < this->qtdeNotas; i++)
            notas[i] = this->notas[i];
        return true;
    }
    return false;
}

bool Aluno::GetNota(int pos, double &val) const
{
    if (pos >= 0 && pos < this->qtdeNotas)
    {
        val = this->notas[pos];
        return true;
    }
    return false;
}

void Aluno::SetQtdNotas(int qtdeNotas)
{
    if (qtdeNotas >= 0)
    {
        this->qtdeNotas = qtdeNotas;
        if (this->notas != NULL)
            delete[] this->notas;
        this->notas = new double[qtdeNotas];
    }
}

int Aluno::GetQtdNotas() const
{
    return this->qtdeNotas;
}

void Aluno::IncrementarContador()
{
    Aluno::contador++;
}

void Aluno::ImprimeTodasNotas() const
{
    for (int i = 0; i < this->qtdeNotas; i++)
        cout << "Nota " << i << ": " << this->notas[i] << endl;
}

Aluno::~Aluno()
{
    if (this->notas != NULL)
        delete[] this->notas;
}
