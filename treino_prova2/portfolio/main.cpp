#include <iostream>
#include "Investidor.h"
#include "InvestidorQualificado.h"
#include "Ativo.h"
#include "Portfolio.h"

int main()
{
    std::cout << "--- Testando Investidor e InvestidorQualificado ---" << std::endl;
    Investidor inv1("Joao Silva", "123.456.789-00");
    inv1.ExibirInfo();

    InvestidorQualificado invQ1("CFA", "Maria Souza", "987.654.321-99");
    invQ1.ExibirInfo();

    std::cout << "\n--- Testando Polimorfismo (Base*) ---" << std::endl;
    Investidor *ptrInv = &invQ1;
    ptrInv->ExibirInfo(); // Deve chamar a versão de InvestidorQualificado

    std::cout << "\n--- Testando Construtor do Portfolio (p1) ---" << std::endl;
    Portfolio p1(invQ1, 5); // Passando InvestidorQualificado
    std::cout << "Capacidade Maxima p1: " << p1.GetCapacidadeMaxima() << std::endl;
    std::cout << "Num Ativos p1: " << p1.GetNumAtivos() << std::endl;

    std::cout << "\n--- Testando AdicionarAtivo ---" << std::endl;
    // Teste AdicionarAtivo (sobrecarga 1)
    Ativo a1("PETR4", 100, 30.0);
    p1.AdicionarAtivo(a1);

    // Teste AdicionarAtivo (sobrecarga 2)
    p1.AdicionarAtivo("VALE3", 50, 60.0);
    p1.AdicionarAtivo("MGLU3", 200, 15.0);

    std::cout << "Novo Num Ativos p1: " << p1.GetNumAtivos() << std::endl;

    std::cout << "\n--- Testando GetValorTotalPortfolio e operator<< (p1) ---" << std::endl;
    // Total = (100*30) + (50*60) + (200*15) = 3000 + 3000 + 3000 = 9000
    std::cout << "Valor total p1 (Get): " << p1.GetValorTotalPortfolio() << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << p1; // Teste do operator<<
    std::cout << "--------------------" << std::endl;

    std::cout << "\n--- Testando operator= (p2 = p1) ---" << std::endl;
    Portfolio p2(inv1, 2); // Portfolio diferente
    std::cout << "P2 ANTES da atribuicao:" << std::endl;
    std::cout << p2;
    std::cout << "--------------------" << std::endl;

    p2 = p1; // Atribuição

    std::cout << "P2 DEPOIS da atribuicao:" << std::endl;
    std::cout << "Capacidade p2: " << p2.GetCapacidadeMaxima() << " (esperado 5)" << std::endl;
    std::cout << "Num Ativos p2: " << p2.GetNumAtivos() << " (esperado 3, mas sera 0 por causa do bug)" << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << p2; // Vai imprimir o dono de p1, mas 0 ativos (devido ao bug)
    std::cout << "--------------------" << std::endl;

    std::cout << "\n--- Teste de Destrutores (automatico) ---" << std::endl;
    return 0; // p1 e p2 serão destruídos aqui
}