#include "Monitor.h"
#include "MonitorBase.h"

int main()
{
    int temperatura = 0;
    double pressao = 0.0;
    std::string status = "NORMAL";

    MonitorBase *monitor[10] = {NULL};

    monitor[0] = new Monitor<int>("temperatura", 100, temperatura);
    monitor[1] = new Monitor<double>("pressao", 50.5, pressao);
    monitor[2] = new Monitor<std::string>("status", "MELTDOWN", status);

    while (status != "MELTDOWN")
    {
        temperatura += 20;
        pressao += 10.1;
        if (temperatura > 100)
            status = "MELTDOWN";

        std::cout << "\n--- Verificando Sensores ---" << std::endl;
        for (int i = 0; i < 10; i++)
            if (monitor[i] != NULL)
                monitor[i]->verificar();
    }

    for (int i = 0; i < 10; i++)
        if (monitor[i] != NULL)
        {
            delete monitor[i];
            monitor[i] = NULL;
        }

    return 0;
}