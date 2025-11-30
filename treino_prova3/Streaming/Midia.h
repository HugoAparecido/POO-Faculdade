#ifndef MIDIA
#define MIDIA

#include <string>

class Midia
{
protected:
    std::string titulo;
    int duracao;

public:
    virtual void Reproduzir() const = 0;
    int GetDuracao()
    {
        return duracao;
    };
    virtual ~Midia() {};
};

#endif