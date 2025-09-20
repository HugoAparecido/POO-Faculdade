#include "Livro.h"
#include <iostream>

unsigned int Livro::contadorLivros = 0;

Livro::Livro(string isbn, string titulo, string autor, int anoPublicacao) : isbn(isbn)
{
    SetTtulo(titulo);
    SetAutor(autor);
    SetAnoPublicacao(anoPublicacao);
    contadorLivros++;
}

string Livro::GetTitulo() const
{
    return this->titulo;
}

string Livro::GetAutor() const
{
    return this->autor;
}

int Livro::GetAnoPublicacao() const
{
    return this->anoPublicacao;
}

string Livro::GetIsbn() const
{
    return this->isbn;
}

int Livro::GetContadorLivros()
{
    return Livro::contadorLivros;
}

void Livro::SetTtulo(string titulo)
{
    this->titulo = titulo;
}

void Livro::SetAutor(string autor)
{
    this->autor = autor;
}

void Livro::SetAnoPublicacao(int anoPublicacao)
{
    this->anoPublicacao = anoPublicacao;
}

Livro::~Livro()
{
    cout << "Livro " << this->titulo << " destruido" << endl;
    contadorLivros--;
}