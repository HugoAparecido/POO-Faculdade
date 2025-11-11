#ifndef INVESTIDOR
#define INVESTIDOR

#include <string>

class Investidor
{
private:
    std::string nome;
    std::string cpf;

public:
    Investidor(std::string nome = "", std::string cpf = "");
    void ExibirInfo() const;
};

#endif
