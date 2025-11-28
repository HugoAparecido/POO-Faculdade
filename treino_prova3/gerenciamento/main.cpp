#include "GerenciadorDePlugins.h"
#include "PluginCalculo.h"
#include "PluginLog.h"
#include "PluginInvalidoException.h"

int main()
{
    try
    {
        GerenciadorDePlugins<Plugin> sistema;

        sistema.registrar(std::make_shared<PluginCalculo>());
        sistema.registrar(std::make_shared<PluginLog>());

        sistema.registrar(nullptr);

        sistema.executarTodos();
    }
    catch (const PluginInvalidoException &e)
    {
        std::cerr << "Exceção capturada: " << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro genérico: " << e.what() << std::endl;
    }

    return 0;
}