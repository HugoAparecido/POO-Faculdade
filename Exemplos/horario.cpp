#include <iostream>
#include <iomanip>

class horario
{

public:
    horario(int h = 0, int m = 0, int s = 0);

    // metodos set
    void set_hora(int h);
    void set_minuto(int m);
    void set_segundo(int s);

    // metodos get
    int get_hora() const;
    int get_minuto() const;
    int get_segundo() const;

    // auxiliar
    void imprime() const;

private:
    int hora, minuto, segundo;
};

horario::horario(int h, int m, int s)
{
    set_hora(h);
    set_minuto(m);
    set_segundo(s);
}

void horario::set_hora(int h)
{
    hora = (h >= 0 && h < 24) ? h : 0;
}

void horario::set_minuto(int m)
{
    minuto = (m >= 0 && m < 59) ? m : 0;
}

void horario::set_segundo(int s)
{
    segundo = (s >= 0 && s < 24) ? s : 0;
}

int horario::get_hora() const
{
    return hora;
}

int horario::get_minuto() const
{
    return minuto;
}

int horario::get_segundo() const
{
    return segundo;
}

void horario::imprime() const
{
    std::cout << std::setfill('0') << std::setw(2) << hora << ":"
              << std::setw(2) << minuto << ":"
              << std::setw(2) << segundo << std::endl;
}

int main()
{

    horario comer(12, 0, 0);
    horario dormir(45, 70, 80);
    const horario meiodia(12, 0, 0);

    std::cout << "horario de comer: ";
    comer.imprime();

    std::cout << "meio dia: ";
    meiodia.imprime();

    std::cout << "horario de dormir: ";
    dormir.imprime();

    // alterando horario de dormir
    dormir.set_hora(23);
    dormir.set_minuto(15);

    std::cout << "horario de dormir modificado: ";
    dormir.imprime();

    // altera��o de objeto constante: ERRO
    // meiodia.set_hora(14);

    system("PAUSE");
}
