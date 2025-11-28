#include "PluginCalculo.h"
#include <iostream>

void PluginCalculo::executar()
{
    std::cout << "Calculando..." << std::endl;
}

std::string PluginCalculo::getNome()
{
    return "Calculo";
}