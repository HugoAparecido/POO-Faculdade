#ifndef PLUGINCALCULO
#define PLUGINCALCULO

#include "Plugin.h"

class PluginCalculo : public Plugin
{
    void executar() override;
    std::string getNome() override;
};

#endif