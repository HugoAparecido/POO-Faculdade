#ifndef GERENCIADORDEPLUGINS
#define GERENCIADORDEPLUGINS

#include <vector>
#include <iostream>
#include <memory>
#include "PluginInvalidoException.h"

template <typename T>

class GerenciadorDePlugins
{
private:
    std::vector<std::shared_ptr<T>> plugins;

public:
    void registrar(std::shared_ptr<T> plugin)
    {
        if (plugin == nullptr)
            throw PluginInvalidoException();
        plugins.push_back(plugin);
        std::cout << "[Gerenciador] Plugin registrado com sucesso.\n";
    }

    void executarTodos()
    {
        if (plugins.empty())
        {
            std::cout << "[Gerenciador] Nenhum plugin carregado." << std::endl;
            return;
        }

        std::cout << "\n--- Executando Plugins ---\n";

        int contador = 0;

        for (const auto &plugin : plugins)
        {
            contador++;

            if (contador == 2)
            {
                std::string msgErro = "Falha interna no plugin " + plugin->getNome();
                throw std::runtime_error(msgErro);
            }

            std::cout << "Plugin: " << plugin->getNome() << " -> ";
            plugin->executar();
        }
        std::cout << "--------------------------\n";
    }
};

#endif