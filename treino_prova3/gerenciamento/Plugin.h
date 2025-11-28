#ifndef PLUGIN
#define PLUGIN

#include <string>

class Plugin
{
public:
    virtual void executar() = 0;
    virtual std::string getNome() = 0;
    virtual ~Plugin() = default;
};

#endif