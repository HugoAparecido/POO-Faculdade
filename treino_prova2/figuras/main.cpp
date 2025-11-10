#include "Figura.h"
#include "Retangulo.h"
#include "Circulo.h"
#include <iostream>
#include <vector>

int main()
{
    Retangulo retangulo1(10, 5);
    Retangulo quadrado1(4);
    Circulo circulo1(3);

    retangulo1.Redimensionar(2.0);
    quadrado1.Redimensionar(8.0, 8.0);

    std::vector<Figura *> figuras;
    figuras.push_back(&retangulo1);
    figuras.push_back(&quadrado1);
    figuras.push_back(&circulo1);

    for (int i = 0; i < 3; i++)
    {
        figuras[i]->ExibirInfo();
        std::cout << std::endl;
        std::cout << figuras[i]->CalcularArea() << std::endl;
        std::cout << figuras[i]->CalcularPerimetro() << std::endl;
    }

    std::cout << *figuras[0];
    if (*figuras[0] == *figuras[1])
        std::cout << "Figuras iguais" << std::endl;
    if (*figuras[0] > *figuras[2])
        std::cout << figuras[0]->GetNome() << " eh maior que " << figuras[2]->GetNome() << std::endl;
    double areaTotal = *figuras[0] + *figuras[1];
    std::cout << areaTotal << std::endl;

    return 0;
}