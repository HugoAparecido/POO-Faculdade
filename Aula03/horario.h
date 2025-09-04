class horario
{
public:
    horario(int = 0, int = 0, int = 0);
    void sethorario(int, int, int);
    void printUniversal();
    void printStandard();

private:
    int hora;
    int minuto;
    int segundo;
};