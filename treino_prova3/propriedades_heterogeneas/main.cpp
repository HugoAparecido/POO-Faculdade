#include "Propriedade.h"
#include "Vetor3D.h"
#include <vector>

int main()
{
    std::vector<PropriedadeBase *> testes;
    testes.push_back(new Propriedade<int>("vidas", 3));
    testes.push_back(new Propriedade<double>("gravidade", 9.81));
    testes.push_back(new Propriedade<std::string>("fase", "Caverna Escura"));
    testes.push_back(new Propriedade<Vetor3D>("posicao_inicial", Vetor3D(0, 5, 10)));
    testes.push_back(new Propriedade<bool>("modo_hardcore", true));
    testes.push_back(new Propriedade<bool>("tutorial_ativo", false));

    for (size_t i = 0; i < testes.size(); i++)
        testes[i]->exibirDetalhes();

    for (size_t i = 0; i < testes.size(); i++)
        delete testes[i];

    testes.clear();

    PropriedadeBase *testeSemVector[7] = {NULL};
    testeSemVector[0] = new Propriedade<int>("vidas", 3);
    testeSemVector[1] = new Propriedade<double>("gravidade", 9.81);
    testeSemVector[2] = new Propriedade<std::string>("fase", "Caverna Escura");
    testeSemVector[3] = new Propriedade<Vetor3D>("posicao_inicial", Vetor3D(0, 5, 10));
    testeSemVector[4] = new Propriedade<bool>("modo_hardcore", true);
    testeSemVector[5] = new Propriedade<bool>("tutorial_ativo", false);

    for (int i = 0; i < 7; i++)
        if (testeSemVector[i] != NULL)
            testeSemVector[i]->exibirDetalhes();

    for (int i = 0; i < 7; i++)
        if (testeSemVector[i] != NULL)
        {
            delete testeSemVector[i];
            testeSemVector[i] = NULL;
        }

    return 0;
}