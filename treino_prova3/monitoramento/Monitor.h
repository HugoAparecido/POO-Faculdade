#ifndef MONITOR
#define MONITOR

#include "MonitorBase.h"

#include <iostream>

template <typename T>
class Monitor : public MonitorBase
{
private:
    std::string nome;
    T limite;
    const T &valorObservado;

public:
    Monitor(std::string nome, T limite, T &variavelMonitorada) : nome(nome), limite(limite), valorObservado(variavelMonitorada) {};

    void verificar() const override
    {
        if (valorObservado > limite)
            std::cout << "[ALERTA] " << nome << " esta perigoso! Valor:" << valorObservado << std::endl;
        else
            std::cout << "[OK] " << nome << " esta estavel" << std::endl;
    }
};

template <>
class Monitor<std::string> : public MonitorBase
{
private:
    std::string nome;
    std::string limite;
    const std::string &valorObservado;

public:
    Monitor(std::string nome, std::string limite, std::string &variavelMonitorada) : nome(nome), limite(limite), valorObservado(variavelMonitorada) {};

    void verificar() const override
    {
        if (valorObservado == limite)
            std::cout << "[ALERTA] " << nome << " esta perigoso! Valor:" << valorObservado << std::endl;
        else
            std::cout << "[OK] " << nome << " esta estavel" << std::endl;
    }
};

#endif