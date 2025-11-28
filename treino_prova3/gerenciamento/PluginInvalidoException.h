#ifndef PLUGININVALIDOEXCEPTION
#define PLUGININVALIDOEXCEPTION

#include <exception>
#include <stdexcept>

class PluginInvalidoException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "ERRO CRITICO: Tentativa de registrar um plugin NULO (nullptr).";
    }
};

#endif