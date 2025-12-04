#ifndef MONITORBASE
#define MONITORBASE

class MonitorBase
{
public:
    virtual void verificar() const = 0;
    virtual ~MonitorBase() {};
};

#endif