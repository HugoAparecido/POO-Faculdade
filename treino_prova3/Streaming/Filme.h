#ifndef FILME
#define FILME

#include "Midia.h"

class Filme : public Midia
{
private:
    std::string resolucao;

public:
    Filme(std::string titulo, int duracao, std::string resolucao = "SD");
    void Reproduzir() const;
};

#endif