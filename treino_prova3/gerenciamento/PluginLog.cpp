#include "PluginLog.h"
#include <iostream>

void PluginLog::executar()
{
    std::cout << "Salvando log..." << std::endl;
}

std::string PluginLog::getNome()
{
    return "Log";
}