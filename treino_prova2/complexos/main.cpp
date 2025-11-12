#include <iostream>
#include "Complexo.h"
#include "VetorComplexo.h"

int main()
{
    std::cout << "--- Testando Construtores e Imprimir ---" << std::endl;

    // Teste Construtor Padrão
    Complexo c1;
    std::cout << "c1 (default): ";
    c1.Imprimir(); // Esperado: 0 + 0i
    std::cout << std::endl;

    // Teste Construtor Parametrizado
    Complexo c2(3.0, 4.0);
    std::cout << "c2 (param):   ";
    c2.Imprimir(); // Esperado: 3 + 4i
    std::cout << std::endl;

    Complexo c3(5.0, -2.0);
    std::cout << "c3 (neg):     ";
    c3.Imprimir(); // Esperado: 5 - 2i
    std::cout << std::endl;

    // ---
    std::cout << "\n--- Testando Set e Get ---" << std::endl;
    c1.Set(1.0, 1.0);
    std::cout << "c1 apos Set(1, 1): ";
    c1.Imprimir(); // Esperado: 1 + 1i
    std::cout << std::endl;
    std::cout << "GetReal() de c1: " << c1.GetReal() << std::endl; // Esperado: 1
    std::cout << "GetImag() de c1: " << c1.GetImag() << std::endl; // Esperado: 1

    // ---
    std::cout << "\n--- Testando Metodos Somar ---" << std::endl;
    // c1 = 1 + 1i
    // c2 = 3 + 4i
    std::cout << "c1 antes: ";
    c1.Imprimir();
    std::cout << std::endl;
    c1.Somar(c2); // c1 = (1+3) + (1+4)i = 4 + 5i
    std::cout << "c1 apos Somar(c2): ";
    c1.Imprimir(); // Esperado: 4 + 5i
    std::cout << std::endl;

    c1.Somar(10.0); // c1 = (4+10) + 5i = 14 + 5i
    std::cout << "c1 apos Somar(10.0): ";
    c1.Imprimir(); // Esperado: 14 + 5i
    std::cout << std::endl;

    // ---
    std::cout << "\n--- Testando Operadores Binarios (+, -, *) ---" << std::endl;
    // c2 = 3 + 4i
    // c3 = 5 - 2i
    Complexo cSoma = c2 + c3; // (3+5) + (4-2)i = 8 + 2i
    std::cout << "c2 + c3: ";
    cSoma.Imprimir(); // Esperado: 8 + 2i
    std::cout << std::endl;

    Complexo cSub = c2 - c3; // (3-5) + (4-(-2))i = -2 + 6i
    std::cout << "c2 - c3: ";
    cSub.Imprimir(); // Esperado: -2 + 6i
    std::cout << std::endl;

    // (3 + 4i) * (5 - 2i) = (3*5 - 4*(-2)) + (3*(-2) + 4*5)i
    // (15 + 8) + (-6 + 20)i = 23 + 14i
    Complexo cMult = c2 * c3;
    std::cout << "c2 * c3: ";
    cMult.Imprimir(); // Esperado: 23 + 14i
    std::cout << std::endl;

    // ---
    std::cout << "\n--- Testando Operadores Incremento (++) ---" << std::endl;
    // c1 = 14 + 5i
    std::cout << "c1 original: ";
    c1.Imprimir();
    std::cout << std::endl;

    // Teste Pré-fixado (++c1)
    Complexo cPreInc = ++c1;
    std::cout << "Resultado de ++c1: ";
    cPreInc.Imprimir();
    std::cout << std::endl; // Esperado: 15 + 5i
    std::cout << "c1 apos ++c1:       ";
    c1.Imprimir();
    std::cout << std::endl; // Esperado: 15 + 5i

    // Teste Pós-fixado (c1++)
    // c1 = 15 + 5i
    Complexo cPostInc = c1++;
    std::cout << "Resultado de c1++: ";
    cPostInc.Imprimir();
    std::cout << std::endl; // Esperado: 15 + 5i (valor antigo)
    std::cout << "c1 apos c1++:       ";
    c1.Imprimir();
    std::cout << std::endl; // Esperado: 16 + 5i (valor novo)

    // ---
    std::cout << "\n--- Testando Operadores Decremento (--) ---" << std::endl;
    // c1 = 16 + 5i
    std::cout << "c1 original: ";
    c1.Imprimir();
    std::cout << std::endl;

    // Teste Pré-fixado (--c1)
    Complexo cPreDec = --c1;
    std::cout << "Resultado de --c1: ";
    cPreDec.Imprimir();
    std::cout << std::endl; // Esperado: 15 + 5i
    std::cout << "c1 apos --c1:       ";
    c1.Imprimir();
    std::cout << std::endl; // Esperado: 15 + 5i

    // Teste Pós-fixado (c1--)
    // c1 = 15 + 5i
    Complexo cPostDec = c1--;
    std::cout << "Resultado de c1--: ";
    cPostDec.Imprimir();
    std::cout << std::endl; // Esperado: 15 + 5i (valor antigo)
    std::cout << "c1 apos c1--:       ";
    c1.Imprimir();
    std::cout << std::endl; // Esperado: 14 + 5i (valor novo)

    std::cout << "\n--- Testando Operadores de Comparação (--) ---" << std::endl;

    std::cin >> c1;
    if (c1 == c2)
        std::cout << c1 << " igual a " << c2 << std::endl;
    if (c1 != c2)
        std::cout << c1 << " diferente a " << c2 << std::endl;

    std::cout << "\n--- Testando Operadores para vetor (--) ---" << std::endl;
    VetorComplexo v1(3);
    v1.SetComplexo(c1, 0);
    std::cout << v1[0];
    VetorComplexo v2(v1);
    v2.SetComplexo(c2, 1);
    VetorComplexo v3(3);
    v3 = v2;
    v3.SetComplexo(c3, 2);
    std::cout << v3.GetTamanhoAtual();
    for (int i = 0; i < v3.GetTamanhoAtual(); i++)
        std::cout << v3[i] << std::endl;

    return 0;
}