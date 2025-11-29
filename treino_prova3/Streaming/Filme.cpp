#include "Filme.h"
#include <iostream>

Filme::Filme(std::string titulo, int duracao, std::string resolucao = "SD")
{
    this->titulo = titulo;
    this->duracao = (duracao > 0) ? duracao : 0;
    this->resolucao = resolucao;
}

void Filme::Reproduzir() const
{
    std::cout << "Assistindo filme " << titulo << " em " << resolucao << std::endl;
}
