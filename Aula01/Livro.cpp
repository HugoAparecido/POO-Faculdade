#include "Livro.h"
#include <iostream>
#include <string>

using namespace std;

void Livro::imprimir() const
{
    cout << "Título: " << this->getTitulo() << endl;
}

void Livro::setTitulo(string titulo)
{
    this->titulo = titulo;
}

string Livro::getTitulo() const
{
    return this->titulo;
}