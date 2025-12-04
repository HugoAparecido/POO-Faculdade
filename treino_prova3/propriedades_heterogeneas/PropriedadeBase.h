#ifndef PROPRIEDADEBASE
#define PROPRIEDADEBASE

class PropriedadeBase
{
public:
    virtual void exibirDetalhes() const = 0;
    virtual ~PropriedadeBase() {};
};

#endif