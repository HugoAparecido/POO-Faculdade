#ifndef INVESTIDORQUALIFICADO
#define INVESTIDORQUALIFICADO

#include "Investidor.h"

class InvestidorQualificado : public Investidor
{
private:
    std::string certificacao;

public:
    InvestidorQualificado(std::string certificacao = "", std::string nome = "", std::string cpf = "");
    void ExibirInfo() const;
};

#endif
