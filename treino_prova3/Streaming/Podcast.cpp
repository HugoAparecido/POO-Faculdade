#include "Podcast.h"
#include <iostream>

Podcast::Podcast(std::string titulo, int duracao, std::string nomeHost)
{
    this->titulo = titulo;
    this->duracao = (duracao > 0) ? duracao : 0;
    this->nomeHost = nomeHost;
}

void Podcast::Reproduzir() const
{
    std::cout << "Ouvindo Podcast " << titulo << " apresentado por " << nomeHost << std::endl;
}
