#ifndef PODCAST
#define PODCAST

#include "Midia.h"

class Podcast : public Midia
{
private:
    std::string nomeHost;

public:
    Podcast(std::string titulo, int duracao, std::string nomeHost = "desconhecido");
    void Reproduzir() const;
};

#endif