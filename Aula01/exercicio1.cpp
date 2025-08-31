//
// Created by hugoaparecido on 8/25/25.
//
#include <iostream>

using namespace std;

struct Time
{
    int horas;
    int minutos;
    int segundos;
};

void inititime(Time *horario, int horas, int minutos, int segundos)
{
    horario->horas = horas;
    horario->minutos = minutos;
    horario->segundos = segundos;
}

void PrintUniversal(Time horario)
{
    cout << horario.horas << ":" << horario.minutos << ":" << horario.segundos << endl;
}

void PrintStandard(Time horario)
{
    if (horario.horas > 12)
        horario.horas = horario.horas % 12;
    cout << horario.horas << ":" << horario.minutos << ":" << horario.segundos << endl;
}

int main()
{
    Time horario_atual;
    inititime(&horario_atual, 12, 30, 59);
    PrintUniversal(horario_atual);
    PrintStandard(horario_atual);

    return 0;
}
